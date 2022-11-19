// Reference: https://github.com/h2zero/NimBLE-Arduino/blob/master/examples/NimBLE_Client/NimBLE_Client.ino

#include <Arduino.h>
#include "TFT_eSPI.h"
#include "lvgl.h"
#include <NimBLEDevice.h>
#include <XboxControllerNotificationParser.h>
#include "XboxController.h"
#include "ui.h"
XboxController controller;
XboxControllerNotificationParser xboxNotif;
void scanEndedCB(NimBLEScanResults results);

static NimBLEAdvertisedDevice* advDevice;

bool scanning = false;
bool connected = false;
static uint32_t scanTime = 0; /** 0 = scan forever */

static NimBLEAddress targetDeviceAddress("68:6c:e6:aa:14:d5");

static NimBLEUUID uuidServiceUnknown("00000001-5f60-4c4f-9c83-a7953298d40d");
static NimBLEUUID uuidServiceGeneral("1801");
static NimBLEUUID uuidServiceBattery("180f");
static NimBLEUUID uuidServiceHid("1812");
static NimBLEUUID uuidCharaReport("2a4d");
static NimBLEUUID uuidCharaPnp("2a50");
static NimBLEUUID uuidCharaHidInformation("2a4a");
static NimBLEUUID uuidCharaPeripheralAppearance("2a01");
static NimBLEUUID uuidCharaPeripheralControlParameters("2a04");

class ClientCallbacks : public NimBLEClientCallbacks {
    void onConnect(NimBLEClient* pClient) {
        Serial.println("Connected");
        connected = true;
        // pClient->updateConnParams(120,120,0,60);
    };

    void onDisconnect(NimBLEClient* pClient) {
        Serial.print(pClient->getPeerAddress().toString().c_str());
        Serial.println(" Disconnected");
        connected = false;
    };

    /** Called when the peripheral requests a change to the connection parameters.
     *  Return true to accept and apply them or false to reject and keep
     *  the currently used parameters. Default will return true.
     */
    bool onConnParamsUpdateRequest(NimBLEClient* pClient,
                                   const ble_gap_upd_params* params) {
        Serial.print("onConnParamsUpdateRequest");
        if (params->itvl_min < 24) { /** 1.25ms units */
            return false;
        } else if (params->itvl_max > 40) { /** 1.25ms units */
            return false;
        } else if (params->latency > 2) { /** Number of intervals allowed to skip */
            return false;
        } else if (params->supervision_timeout > 100) { /** 10ms units */
            return false;
        }

        return true;
    };

    /********************* Security handled here **********************
    ****** Note: these are the same return values as defaults ********/
    uint32_t onPassKeyRequest() {
        Serial.println("Client Passkey Request");
        /** return the passkey to send to the server */
        return 0;
    };

    bool onConfirmPIN(uint32_t pass_key) {
        Serial.print("The passkey YES/NO number: ");
        Serial.println(pass_key);
        /** Return false if passkeys don't match. */
        return true;
    };

    /** Pairing process complete, we can check the results in ble_gap_conn_desc */
    void onAuthenticationComplete(ble_gap_conn_desc* desc) {
        Serial.println("onAuthenticationComplete");
        if (!desc->sec_state.encrypted) {
            Serial.println("Encrypt connection failed - disconnecting");
            /** Find the client with the connection handle provided in desc */
            NimBLEDevice::getClientByID(desc->conn_handle)->disconnect();
            return;
        }
    };
};

/** Define a class to handle the callbacks when advertisments are received */
class AdvertisedDeviceCallbacks : public NimBLEAdvertisedDeviceCallbacks {
    void onResult(NimBLEAdvertisedDevice* advertisedDevice) {
        Serial.print("Advertised Device found: ");
        Serial.println(advertisedDevice->toString().c_str());
        Serial.printf("name:%s, address:%s\n", advertisedDevice->getName().c_str(),
                      advertisedDevice->getAddress().toString().c_str());
        Serial.printf("uuidService:%s\n",
                      advertisedDevice->haveServiceUUID()
                      ? advertisedDevice->getServiceUUID().toString().c_str()
                      : "none");

        if (advertisedDevice->getAddress().equals(targetDeviceAddress))
            // if (advertisedDevice->isAdvertisingService(uuidServiceHid))
        {
            Serial.println("Found Our Service");
            /** stop scan before connecting */
            NimBLEDevice::getScan()->stop();
            /** Save the device reference in a global for the client to use*/
            advDevice = advertisedDevice;
        }
    };
};
void updateUi(){
    if(ui_Screen1_Slider1){
        lv_slider_set_value(ui_Screen1_Slider1,xboxNotif.joyLHori,LV_ANIM_ON);
    }
    if(ui_Screen1_Slider2){
        lv_slider_set_value(ui_Screen1_Slider2,xboxNotif.joyRHori,LV_ANIM_ON);
    }
    if(ui_Screen1_Slider3){
        lv_slider_set_value(ui_Screen1_Slider3,xboxNotif.trigLT,LV_ANIM_ON);
    }
    if(ui_Screen1_Slider4){
        lv_slider_set_value(ui_Screen1_Slider4,xboxNotif.trigRT,LV_ANIM_ON);
    }
    if(ui_Screen1_Slider5){
        lv_slider_set_value(ui_Screen1_Slider5,xboxNotif.joyLVert,LV_ANIM_ON);
    }
    if(ui_Screen1_Slider6){
        lv_slider_set_value(ui_Screen1_Slider6,xboxNotif.joyRVert,LV_ANIM_ON);
    }
}
unsigned long printInterval = 100UL;

/** Notification / Indication receiving handler callback */
void notifyCB(NimBLERemoteCharacteristic* pRemoteCharacteristic, uint8_t* pData,
              size_t length, bool isNotify) {
    static bool isPrinting = false;
    static unsigned long printedAt = 0;
    if (isPrinting || millis() - printedAt < printInterval) return;
    isPrinting = true;
    std::string str = (isNotify == true) ? "Notification" : "Indication";
    str += " from ";
    /** NimBLEAddress and NimBLEUUID have std::string operators */
    str += std::string(
            pRemoteCharacteristic->getRemoteService()->getClient()->getPeerAddress());
    str += ": Service = " +
           std::string(pRemoteCharacteristic->getRemoteService()->getUUID());
    str += ", Characteristic = " + std::string(pRemoteCharacteristic->getUUID());
    // str += ", Value = " + std::string((char*)pData, length);
    Serial.println(str.c_str());
    Serial.print("value: ");
    for (int i = 0; i < length; ++i) {
        Serial.printf(" %02x", pData[i]);
    }
    Serial.println("");
    xboxNotif.update(pData, length);
   // Serial.print(xboxNotif.toString());
    updateUi();
    printedAt = millis();
    isPrinting = false;
}

void scanEndedCB(NimBLEScanResults results) {
    Serial.println("Scan Ended");
    scanning = false;
}

static ClientCallbacks clientCB;

void charaPrintId(NimBLERemoteCharacteristic* pChara) {
    Serial.printf("s:%s c:%s h:%d",
                  pChara->getRemoteService()->getUUID().toString().c_str(),
                  pChara->getUUID().toString().c_str(), pChara->getHandle());
}

void printValue(std::__cxx11::string str) {
    Serial.printf("str: %s\n", str.c_str());
    Serial.printf("hex:");
    for (auto v : str) {
        Serial.printf(" %02x", v);
    }
    Serial.println("");
}

void charaRead(NimBLERemoteCharacteristic* pChara) {
    if (pChara->canRead()) {
        charaPrintId(pChara);
        Serial.println(" canRead");
        auto str = pChara->readValue();
        if (str.size() == 0) {
            str = pChara->readValue();
        }
        printValue(str);
    }
}

void charaSubscribeNotification(NimBLERemoteCharacteristic* pChara) {
    if (pChara->canNotify()) {
        charaPrintId(pChara);
        Serial.println(" canNotify ");
        if (pChara->subscribe(true, notifyCB, true)) {
            Serial.println("set notifyCb");
            // return true;
        } else {
            Serial.println("failed to subscribe");
        }
    }
}

bool afterConnect(NimBLEClient* pClient) {
    for (auto pService : *pClient->getServices(true)) {
        auto sUuid = pService->getUUID();
        if (!sUuid.equals(uuidServiceHid)) {
            continue;  // skip
        }
        Serial.println(pService->toString().c_str());
        for (auto pChara : *pService->getCharacteristics(true)) {
            charaRead(pChara);
            charaSubscribeNotification(pChara);
        }
    }

    return true;
}

/** Handles the provisioning of clients and connects / interfaces with the
 * server */
bool connectToServer(NimBLEAdvertisedDevice* advDevice) {
    NimBLEClient* pClient = nullptr;

    /** Check if we have a client we should reuse first **/
    if (NimBLEDevice::getClientListSize()) {
        pClient = NimBLEDevice::getClientByPeerAddress(advDevice->getAddress());
        if (pClient) {
            pClient->connect();
        }
    }

    /** No client to reuse? Create a new one. */
    if (!pClient) {
        if (NimBLEDevice::getClientListSize() >= NIMBLE_MAX_CONNECTIONS) {
            Serial.println("Max clients reached - no more connections available");
            return false;
        }

        pClient = NimBLEDevice::createClient();

        Serial.println("New client created");

        pClient->setClientCallbacks(&clientCB, false);
        pClient->setConnectionParams(12, 12, 0, 51);
        pClient->setConnectTimeout(5);
        pClient->connect(advDevice, false);
    }

    int retryCount = 5;
    while (!pClient->isConnected()) {
        if (retryCount <= 0) {
            return false;
        } else {
            Serial.println("try connection again " + String(millis()));
            delay(1000);
        }

        NimBLEDevice::getScan()->stop();
        pClient->disconnect();
        delay(500);
        // Serial.println(pClient->toString().c_str());
        pClient->connect(true);
        --retryCount;
    }

    Serial.print("Connected to: ");
    Serial.println(pClient->getPeerAddress().toString().c_str());
    Serial.print("RSSI: ");
    Serial.println(pClient->getRssi());

    pClient->discoverAttributes();

    bool result = afterConnect(pClient);
    if (!result) {
        return result;
    }

    Serial.println("Done with this device!");
    return true;
}
void startScan() {
    scanning = true;
    auto pScan = NimBLEDevice::getScan();
    pScan->setAdvertisedDeviceCallbacks(new AdvertisedDeviceCallbacks());
    pScan->setInterval(45);
    pScan->setWindow(15);
    Serial.println("Start scan");
    pScan->start(scanTime, scanEndedCB);
}

static lv_disp_draw_buf_t draw_buf;    //定义显示器变量
static lv_color_t buf[TFT_WIDTH * 10]; //定义刷新缓存

TFT_eSPI tft = TFT_eSPI();

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();                                        //使能写功能
    tft.setAddrWindow(area->x1, area->y1, w, h);             //设置填充区域
    tft.pushColors((uint16_t *)&color_p->full, w * h, true); //写入颜色缓存和缓存大小
    tft.endWrite();                                          //关闭写功能

    lv_disp_flush_ready(disp); //调用区域填充颜色函数
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}
static void button_init(void)
{
    /*Your code comes here*/
}

static void button_read1(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnLB){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read2(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnRB){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read3(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnDirUp){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read4(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnDirLeft){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read5(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnDirDown){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read6(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnDirRight){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read7(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnY){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read8(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnX){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read9(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnA){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read10(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnB){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read11(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnSelect){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read12(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnStart){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read13(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnLS){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read14(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnRS){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read15(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnShare){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

static void button_read16(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint8_t last_btn = 0;
    /*Get the pressed button's ID*/
    int8_t btn_act = -1;
    if(xboxNotif.btnXbox){
        btn_act = 0;
    }
    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->btn_id = last_btn;
}

void setup() {
    Serial.begin(115200);
#if 1
    tft.init();         //初始化
    tft.setRotation(1); //屏幕旋转方向（横向）
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    //disp_drv.sw_rotate = 1; // add for rotation
    //disp_drv.rotated = LV_DISP_ROT_90; // add for rotation
    lv_disp_drv_register(&disp_drv);
    ui_init();
    /*Initialize your button if you have*/
    button_init();

    static lv_indev_drv_t indev_drv1;
    lv_indev_t * indev_butto1;
    lv_indev_drv_init(&indev_drv1);
    indev_drv1.type = LV_INDEV_TYPE_BUTTON;
    indev_drv1.read_cb = button_read1;
    indev_butto1 = lv_indev_drv_register(&indev_drv1);
    static const lv_point_t btn_point1[1] = {
            {28, 10}
    };
    lv_indev_set_button_points(indev_butto1, btn_point1);

    static lv_indev_drv_t indev_drv2;
    lv_indev_t * indev_butto2;
    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;
    indev_drv2.read_cb = button_read2;
    indev_butto2 = lv_indev_drv_register(&indev_drv2);
    static const lv_point_t btn_point2[1] = {
            {129, 11}
    };
    lv_indev_set_button_points(indev_butto2, btn_point2);

    static lv_indev_drv_t indev_drv3;
    lv_indev_t * indev_butto3;
    lv_indev_drv_init(&indev_drv3);
    indev_drv3.type = LV_INDEV_TYPE_BUTTON;
    indev_drv3.read_cb = button_read3;
    indev_butto3 = lv_indev_drv_register(&indev_drv3);
    static const lv_point_t btn_point3[1] = {
            {30, 32}
    };
    lv_indev_set_button_points(indev_butto3, btn_point3);

    static lv_indev_drv_t indev_drv4;
    lv_indev_t * indev_butto4;
    lv_indev_drv_init(&indev_drv4);
    indev_drv4.type = LV_INDEV_TYPE_BUTTON;
    indev_drv4.read_cb = button_read4;
    indev_butto4 = lv_indev_drv_register(&indev_drv4);
    static const lv_point_t btn_point4[1] = {
            {17, 46}
    };
    lv_indev_set_button_points(indev_butto4, btn_point4);

    static lv_indev_drv_t indev_drv5;
    lv_indev_t * indev_butto5;
    lv_indev_drv_init(&indev_drv5);
    indev_drv5.type = LV_INDEV_TYPE_BUTTON;
    indev_drv5.read_cb = button_read5;
    indev_butto5 = lv_indev_drv_register(&indev_drv5);
    static const lv_point_t btn_point5[1] = {
            {30, 60}
    };
    lv_indev_set_button_points(indev_butto5, btn_point5);

    static lv_indev_drv_t indev_drv6;
    lv_indev_t * indev_butto6;
    lv_indev_drv_init(&indev_drv6);
    indev_drv6.type = LV_INDEV_TYPE_BUTTON;
    indev_drv6.read_cb = button_read6;
    indev_butto6 = lv_indev_drv_register(&indev_drv6);
    static const lv_point_t btn_point6[1] = {
            {45, 45}
    };
    lv_indev_set_button_points(indev_butto6, btn_point6);

    static lv_indev_drv_t indev_drv7;
    lv_indev_t * indev_butto7;
    lv_indev_drv_init(&indev_drv7);
    indev_drv7.type = LV_INDEV_TYPE_BUTTON;
    indev_drv7.read_cb = button_read7;
    indev_butto7 = lv_indev_drv_register(&indev_drv7);
    static const lv_point_t btn_point7[1] = {
            {122, 26}
    };
    lv_indev_set_button_points(indev_butto7, btn_point7);

    static lv_indev_drv_t indev_drv8;
    lv_indev_t * indev_butto8;
    lv_indev_drv_init(&indev_drv8);
    indev_drv8.type = LV_INDEV_TYPE_BUTTON;
    indev_drv8.read_cb = button_read8;
    indev_butto8 = lv_indev_drv_register(&indev_drv8);
    static const lv_point_t btn_point8[1] = {
            {107, 39}
    };
    lv_indev_set_button_points(indev_butto8, btn_point8);

    static lv_indev_drv_t indev_drv9;
    lv_indev_t * indev_butto9;
    lv_indev_drv_init(&indev_drv9);
    indev_drv9.type = LV_INDEV_TYPE_BUTTON;
    indev_drv9.read_cb = button_read9;
    indev_butto9 = lv_indev_drv_register(&indev_drv9);
    static const lv_point_t btn_point9[1] = {
            {123, 53}
    };
    lv_indev_set_button_points(indev_butto9, btn_point9);

    static lv_indev_drv_t indev_drv10;
    lv_indev_t * indev_butto10;
    lv_indev_drv_init(&indev_drv10);
    indev_drv10.type = LV_INDEV_TYPE_BUTTON;
    indev_drv10.read_cb = button_read10;
    indev_butto10 = lv_indev_drv_register(&indev_drv10);
    static const lv_point_t btn_point10[1] = {
            {138, 40}
    };
    lv_indev_set_button_points(indev_butto10, btn_point10);

    static lv_indev_drv_t indev_drv11;
    lv_indev_t * indev_butto11;
    lv_indev_drv_init(&indev_drv11);
    indev_drv11.type = LV_INDEV_TYPE_BUTTON;
    indev_drv11.read_cb = button_read11;
    indev_butto11 = lv_indev_drv_register(&indev_drv11);
    static const lv_point_t btn_point11[1] = {
            {68, 20}
    };
    lv_indev_set_button_points(indev_butto11, btn_point11);

    static lv_indev_drv_t indev_drv12;
    lv_indev_t * indev_butto12;
    lv_indev_drv_init(&indev_drv12);
    indev_drv12.type = LV_INDEV_TYPE_BUTTON;
    indev_drv12.read_cb = button_read12;
    indev_butto12 = lv_indev_drv_register(&indev_drv12);
    static const lv_point_t btn_point12[1] = {
            {91, 20}
    };
    lv_indev_set_button_points(indev_butto12, btn_point12);

    static lv_indev_drv_t indev_drv13;
    lv_indev_t * indev_butto13;
    lv_indev_drv_init(&indev_drv13);
    indev_drv13.type = LV_INDEV_TYPE_BUTTON;
    indev_drv13.read_cb = button_read13;
    indev_butto13 = lv_indev_drv_register(&indev_drv13);
    static const lv_point_t btn_point13[1] = {
            {1, 14}
    };
    lv_indev_set_button_points(indev_butto13, btn_point13);

    static lv_indev_drv_t indev_drv14;
    lv_indev_t * indev_butto14;
    lv_indev_drv_init(&indev_drv14);
    indev_drv14.type = LV_INDEV_TYPE_BUTTON;
    indev_drv14.read_cb = button_read14;
    indev_butto14 = lv_indev_drv_register(&indev_drv14);
    static const lv_point_t btn_point14[1] = {
            {85, 60}
    };
    lv_indev_set_button_points(indev_butto14, btn_point14);

    static lv_indev_drv_t indev_drv15;
    lv_indev_t * indev_butto15;
    lv_indev_drv_init(&indev_drv15);
    indev_drv15.type = LV_INDEV_TYPE_BUTTON;
    indev_drv15.read_cb = button_read15;
    indev_butto15 = lv_indev_drv_register(&indev_drv15);
    static const lv_point_t btn_point15[1] = {
            {77, 35}
    };
    lv_indev_set_button_points(indev_butto15, btn_point15);

    static lv_indev_drv_t indev_drv16;
    lv_indev_t * indev_butto16;
    lv_indev_drv_init(&indev_drv16);
    indev_drv16.type = LV_INDEV_TYPE_BUTTON;
    indev_drv16.read_cb = button_read16;
    indev_butto16 = lv_indev_drv_register(&indev_drv16);
    static const lv_point_t btn_point16[1] = {
            {78, 6}
    };
    lv_indev_set_button_points(indev_butto16, btn_point16);
    
    lv_group_t *g= lv_group_create();
    lv_group_set_default(g);

#endif
#if 1
    Serial.println("Starting NimBLE Client");
    /** Initialize NimBLE, no device name spcified as we are not advertising */
    NimBLEDevice::init("");
    NimBLEDevice::setOwnAddrType(BLE_OWN_ADDR_RANDOM);
    NimBLEDevice::setSecurityAuth(true, true, true);
    NimBLEDevice::setPower(ESP_PWR_LVL_P9); /** +9db */
#endif
}

void loop() {
#if 1
    if (!connected) {
        if (!scanning && advDevice == nullptr) {
            startScan();
        }
        if (advDevice != nullptr) {
            if (connectToServer(advDevice)) {
                Serial.println("Success! we should now be getting notifications");
            } else {
                Serial.println("Failed to connect");
            }
            advDevice = nullptr;
        }
    }
#endif
    //Serial.println("scanning:" + String(scanning) + " connected:" + String(connected) + " advDevice is nullptr:" + String(advDevice == nullptr));
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}
