#include <jni.h>
#include <string>

#include "CommonClass.hpp"

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestAck(JNIEnv* env, jobject) {
    ByrobotProtocol::CRequest *request = new ByrobotProtocol::CRequest();

    request->dataType = ByrobotProtocol::DataType::State;
    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestFlight(JNIEnv* env, jobject) {
    ByrobotProtocol::CRequest *request = new ByrobotProtocol::CRequest();

    request->dataType = ByrobotProtocol::DataType::CountFlight;
    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestDrive(JNIEnv* env, jobject) {
    ByrobotProtocol::CRequest *request = new ByrobotProtocol::CRequest();

    request->dataType = ByrobotProtocol::DataType::CountDrive;
    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestUpdate(JNIEnv* env, jobject, jbyteArray arrayBuffer, int idxBuffer) {
    ByrobotProtocol::CUpdate *request = new ByrobotProtocol::CUpdate();
    jboolean isCopy;
    jbyte* bufferPtr = (jbyte*) env->GetByteArrayElements(arrayBuffer, &isCopy);
    jsize lengthOfArray = env->GetArrayLength(arrayBuffer);

    request->indexBlock = idxBuffer;
    for( int i = 0;  i < 16; ++i ) {
        request->dataBlock[i] = (uint8_t )(bufferPtr[i] & 0xff);
    }

    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    env->ReleaseByteArrayElements(arrayBuffer, bufferPtr, 0);

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestLookupMain(JNIEnv* env, jobject) {
    ByrobotProtocol::CUpdateLookupTarget *request = new ByrobotProtocol::CUpdateLookupTarget();

    request->deviceType = ByrobotProtocol::Firmware::DeviceType::PetroneMain;
    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestLookupSub(JNIEnv* env, jobject) {
    ByrobotProtocol::CUpdateLookupTarget *request = new ByrobotProtocol::CUpdateLookupTarget();

    request->deviceType = ByrobotProtocol::Firmware::DeviceType::PetroneSub;
    jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                            (jbyte *) request->ToTransferDataBlock());

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestControl(JNIEnv* env, jobject, int leftX, int leftY, int rightX, int rightY) {
    ByrobotProtocol::CControl *control = new ByrobotProtocol::CControl();

    control->throttle = (int8_t)(leftY);
    control->yaw = (int8_t)((leftX));
    control->pitch = (int8_t)(rightY);
    control->roll = (int8_t)(rightX);

    jbyteArray javaBytes = env->NewByteArray(control->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, control->GetSize()+1, (jbyte *) control->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_setPetroneMode(JNIEnv* env, jobject, int mode) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    if( mode < 0x20)  led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    else led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Blue;
    led->ledEvent->interval         = 100;
    led->ledEvent->repeat           = 2;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::ModePetrone;
    led->ledCommand->option        = mode;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_setAxisMode(JNIEnv* env, jobject, jboolean mode) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Green;
    led->ledEvent->interval         = 1;
    led->ledEvent->repeat           = 3;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::Coordinate;
    if (mode) {
        led->ledCommand->option         = ByrobotProtocol::Coordinate::Absolute;
    } else {
        led->ledCommand->option         = ByrobotProtocol::Coordinate::Relative;
    }

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_setTrimMode(JNIEnv* env, jobject, jint throttle, jint pitch, jint roll, jint yaw, jint wheel ) {
    ByrobotProtocol::CTrimAll *trim = new ByrobotProtocol::CTrimAll();

    trim->flight.roll  = roll;
    trim->flight.pitch  = pitch;
    trim->flight.throttle = throttle;
    trim->flight.yaw = yaw;
    trim->drive.wheel = wheel;

    jbyteArray javaBytes = env->NewByteArray(trim->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, trim->GetSize()+1, (jbyte *) trim->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestTakeoff(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 0;
    led->ledEvent->repeat           = 0;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option        = ByrobotProtocol::FlightEvent::TakeOff;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestChangeColorArm(JNIEnv* env, jobject, jint red, jint green, jint blue )
{
    ByrobotProtocol::CLedModeColor *request = new ByrobotProtocol::CLedModeColor();
    request->ledModeColorBase->mode = ByrobotProtocol::Light::Mode::ArmHold;
    request->ledModeColorBase->red = red;
    request->ledModeColorBase->green = green;
    request->ledModeColorBase->blue = blue;
    request->ledModeColorBase->interval = 255;

    jbyteArray javaBytes = env->NewByteArray(request->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize()+1, (jbyte *) request->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestChangeColorEye(JNIEnv* env, jobject, jint red, jint green, jint blue )
{
    ByrobotProtocol::CLedModeColor *request = new ByrobotProtocol::CLedModeColor();
    request->ledModeColorBase->mode = ByrobotProtocol::Light::Mode::EyeHold;
    request->ledModeColorBase->red = red;
    request->ledModeColorBase->green = green;
    request->ledModeColorBase->blue = blue;
    request->ledModeColorBase->interval = 255;

    jbyteArray javaBytes = env->NewByteArray(request->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize()+1, (jbyte *) request->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestLEDColor(JNIEnv* env, jobject,  jint eye, jint arm )
{
    ByrobotProtocol::CLedMode2 *request = new ByrobotProtocol::CLedMode2();
    request->ledMode1->mode     = ByrobotProtocol::Light::Mode::EyeHold;
    request->ledMode1->colors   = (ByrobotProtocol::Light::Colors::Enum)eye;
    request->ledMode1->interval = 255;
    request->ledMode2->mode     = ByrobotProtocol::Light::Mode::ArmHold;
    request->ledMode2->colors   = (ByrobotProtocol::Light::Colors::Enum)arm;
    request->ledMode2->interval = 255;

    jbyteArray javaBytes = env->NewByteArray(request->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize()+1, (jbyte *) request->ToTransferDataBlock() );

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestChangeColor(JNIEnv* env, jobject, jint redE, jint greenE, jint blueE, jint redA, jint greenA, jint blueA )
{
    ByrobotProtocol::CLedModeColor2 *request = new ByrobotProtocol::CLedModeColor2();
    request->ledModeColorBase1->mode = ByrobotProtocol::Light::Mode::EyeHold;
    request->ledModeColorBase1->red = redE;
    request->ledModeColorBase1->green = greenE;
    request->ledModeColorBase1->blue = blueE;
    request->ledModeColorBase1->interval = 255;
    request->ledModeColorBase2->mode = ByrobotProtocol::Light::Mode::ArmHold;
    request->ledModeColorBase2->red = redA;
    request->ledModeColorBase2->green = greenA;
    request->ledModeColorBase2->blue = blueA;
    request->ledModeColorBase2->interval = 255;

    jbyteArray javaBytes = env->NewByteArray(request->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize()+1, (jbyte *) request->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestLanding(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 0;
    led->ledEvent->repeat           = 0;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option        = ByrobotProtocol::FlightEvent::Landing;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestEmStop(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 0;
    led->ledEvent->repeat           = 0;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option        = ByrobotProtocol::FlightEvent::Stop;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestDriveStop(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 0;
    led->ledEvent->repeat           = 0;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::DriveEvent;
    led->ledCommand->option        = ByrobotProtocol::DriveEvent::Stop;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestIR(JNIEnv* env, jobject, jboolean isRed, jboolean isFlight,  jbyteArray irdata )
{
    ByrobotProtocol::CLedEventCommandIr *led = new ByrobotProtocol::CLedEventCommandIr();

    jbyte* bufferPtr = env->GetByteArrayElements(irdata, NULL);

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = isRed ? ByrobotProtocol::Light::Colors::Red : ByrobotProtocol::Light::Colors::Blue;
    led->ledEvent->interval         = 2;
    led->ledEvent->repeat           = 1;
    led->ledCommand->commandType    = isFlight ? ByrobotProtocol::CommandType::FlightEvent : ByrobotProtocol::CommandType::DriveEvent;
    led->ledCommand->option         = isFlight ? ByrobotProtocol::FlightEvent::Shot : ByrobotProtocol::DriveEvent::Shot;
    led->irData                     = (bufferPtr[3] << 24) | (bufferPtr[2] << 16) | (bufferPtr[1] << 8) | (bufferPtr[0]); //(uint32_t)bufferPtr[0] + ( ((uint32_t)bufferPtr[1]) << 8 & 0x0000ff00 ) + ( ((uint32_t)bufferPtr[1]) << 16 & 0x00ff0000 ) + ( ((uint32_t)bufferPtr[1]) << 24 & 0xff000000 );

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestIRIntRedFlight(JNIEnv* env, jobject, jint irdata )
{
    ByrobotProtocol::CLedEventCommandIr *led = new ByrobotProtocol::CLedEventCommandIr();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 2;
    led->ledEvent->repeat           = 1;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option         = ByrobotProtocol::FlightEvent::Shot;
    led->irData                     = irdata;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestIRIntBlueFlight(JNIEnv* env, jobject, jint irdata )
{
    ByrobotProtocol::CLedEventCommandIr *led = new ByrobotProtocol::CLedEventCommandIr();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Blue;
    led->ledEvent->interval         = 2;
    led->ledEvent->repeat           = 1;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option         = ByrobotProtocol::FlightEvent::Shot;
    led->irData                     = irdata;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestIRIntRedDrive(JNIEnv* env, jobject, jint irdata )
{
    ByrobotProtocol::CLedEventCommandIr *led = new ByrobotProtocol::CLedEventCommandIr();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 2;
    led->ledEvent->repeat           = 1;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::DriveEvent;
    led->ledCommand->option         = ByrobotProtocol::DriveEvent::Shot;
    led->irData                     = irdata;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestIRIntBlueDrive(JNIEnv* env, jobject, jint irdata )
{
    ByrobotProtocol::CLedEventCommandIr *led = new ByrobotProtocol::CLedEventCommandIr();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlicker;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Blue;
    led->ledEvent->interval         = 2;
    led->ledEvent->repeat           = 1;
    led->ledCommand->commandType    = ByrobotProtocol::CommandType::DriveEvent;
    led->ledCommand->option         = ByrobotProtocol::DriveEvent::Shot;
    led->irData                     = irdata;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_sendAbsoulute(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmFlickerDouble;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Violet;
    led->ledEvent->interval         = 200;
    led->ledEvent->repeat           = 2;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::ResetHeading;
    led->ledCommand->option        =0;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestTrimAll(JNIEnv* env, jobject) {
    ByrobotProtocol::CRequest *request = new ByrobotProtocol::CRequest();

    request->dataType = ByrobotProtocol::DataType::TrimFlight;

    jbyteArray javaBytes = env->NewByteArray(request->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, request->GetSize()+1, (jbyte *) request->ToTransferDataBlock() );

    return javaBytes;
}


extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_sendTurn(JNIEnv* env, jobject) {
    ByrobotProtocol::CLedEventCommand *led = new ByrobotProtocol::CLedEventCommand();

    led->ledEvent->mode             = ByrobotProtocol::Light::Mode::ArmHold;
    led->ledEvent->colors           = ByrobotProtocol::Light::Colors::Red;
    led->ledEvent->interval         = 0;
    led->ledEvent->repeat           = 0;
    led->ledCommand->commandType   = ByrobotProtocol::CommandType::FlightEvent;
    led->ledCommand->option        = ByrobotProtocol::FlightEvent::Rotate180;

    jbyteArray javaBytes = env->NewByteArray(led->GetSize()+1);
    env->SetByteArrayRegion(javaBytes, 0, led->GetSize()+1, (jbyte *) led->ToTransferDataBlock() );

    return javaBytes;
}

