# PETRONE
***BLE / Protocol / DataType***<br>
Modified : 2017.03.23


---

**DataType**
-----------------
**Protocol::DataType::Type**

데이터 타입

```cpp
namespace DataType
{
    enum Type
    {
        None = 0,               ///< 없음

        // -- BLE -----------------------------------------------------------
        // 시스템 정보
        Ping,                   ///< 통신 확인(reserved)
        Ack,                    ///< 데이터 수신에 대한 응답
        Error,                  ///< 오류(reserved, 비트 플래그는 추후에 지정)
        Request,                ///< 지정한 타입의 데이터 요청
        
        // 조종, 명령 
        Control = 0x10,         ///< 조종
        Command,                ///< 명령

namespace DataType
{
    enum Type
    {
        None = 0,               // 없음

        // -- BLE ---------------------------------------------------------
        // 시스템 정보
        Ping,                   // 통신 확인(reserved)
        Ack,                    // 데이터 수신에 대한 응답
        Error,                  // 오류(reserved, 비트 플래그는 추후에 지정)
        Request,                // 지정한 타입의 데이터 요청
        
        // 조종, 명령 
        Control = 0x10,         // 조종
        Command,                // 명령
        Command2,               // 다중 명령(2가지 설정을 동시에 변경)
        Command3,               // 다중 명령(3가지 설정을 동시에 변경)
        
        // LED
        LedMode = 0x20,         // LED 모드 지정
        LedMode2,               // LED 모드 2개 지정
        LedModeCommand,         // LED 모드, 커맨드
        LedModeCommandIr,       // LED 모드, 커맨드, IR 데이터 송신
        LedModeColor,           // LED 모드 3색 직접 지정
        LedModeColor2,          // LED 모드 3색 직접 지정 2개
        
        LedEvent,               // LED 이벤트
        LedEvent2,              // LED 이벤트 2개, 
        LedEventCommand,        // LED 이벤트, 커맨드
        LedEventCommandIr,      // LED 이벤트, 커맨드, IR 데이터 송신
        LedEventColor,          // LED 이벤트 3색 직접 지정
        LedEventColor2,         // LED 이벤트 3색 직접 지정 2개
        
        LedModeDefaultColor,    // LED 초기 모드 3색 직접 지정
        LedModeDefaultColor2,   // LED 초기 모드 3색 직접 지정 2개
        
        // 상태 
        Address = 0x30,         // IEEE address
        State,                  // 드론의 상태(비행 모드, 방위기준, 배터리량)
        Attitude,               // 드론의 자세(Vector)
        GyroBias,               // 자이로 바이어스 값(Vector)
        TrimAll,                // 전체 트림
        TrimFlight,             // 비행 트림
        TrimDrive,              // 주행 트림
        
        CountFlight,            // 비행 관련 카운트 
        CountDrive,             // 주행 관련 카운트 
        
        // 데이터 송수신
        IrMessage = 0x40,       // IR 데이터 송수신
        
        
        // 센서 및 제어
        ImuRawAndAngle = 0x50,  // IMU Raw + Angle
        Pressure,               // 압력 센서 데이터
        ImageFlow,              // ImageFlow
        Button,                 // 버튼 입력
        Battery,                // 배터리
        Motor,                  // 모터 제어 및 현재 제어값 확인
        Temperature,            // 온도 데이터
        Range,                  // 거리 센서
        
        EndOfType
    };
}
```

[Home](README.md)
