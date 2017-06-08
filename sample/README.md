
# BYROBOT PETRONE 
# Common packet class and structs sample  code.

### Common class functions.
Bluetooth packet block : 
    byte* block = pakcet->ToTransferDataBlock();
    packet_size = GetSize() + 1;
    

FPV(Wifi) packet block :
    byte* block = pakcet->ToTransferDataBlockWifi();
    packet_size = GetSize() + 6;


### Usage
Request Petrone Status packet :
    extern "C" jbyteArray Java_co_kr_byrobot_common_controller_PetroneBleManager_requestAck(JNIEnv* env, jobject) {
        ByrobotProtocol::CRequest *request = new ByrobotProtocol::CRequest();

        request->dataType = ByrobotProtocol::DataType::State;
        jbyteArray javaBytes = env->NewByteArray(request->GetSize() + 1);
        env->SetByteArrayRegion(javaBytes, 0, request->GetSize() + 1,
                                (jbyte *) request->ToTransferDataBlock());

        return javaBytes;
    }

[EMail](mailto://dev@byrobot.co.kr)