# PETRONE
***BLE / Protocol***<br>
Modified : 2017.03.23

---

#### Petrone에서 사용하고 있는 정의들을 소개합니다.

---

**CommandType**
-----------------
**Protocol::CommandType**<br>
CommandBase 구조체에서 commandType 변수에 사용하는 값입니다.
```cpp
namespace Protocol
{
    namespace CommandType
    {
        enum Type
        {
            None = 0,                       ///< 이벤트 없음
            
            // 설정
            ModePetrone = 0x10,             ///< 페트론 동작 모드 전환
            
            // 제어
            Coordinate = 0x20,              ///< 방위 기준 변경
            Trim,                           ///< 트림 변경
            FlightEvent,                    ///< 비행 이벤트 실행
            DriveEvent,                     ///< 주행 이벤트 실행
            Stop,                           ///< 정지
            
            ResetHeading = 0x50,            ///< 방향을 리셋(앱솔루트 모드 일 때 현재 heading을 0도로 변경)
            ClearGyroBiasAndTrim,           ///< 자이로 바이어스와 트림 설정 초기화
            ClearTrim,                      ///< 트림 초기화
            
            // 통신[Bluetooth]
            PairingActivate = 0x80,         ///< 페어링 활성화
            PairingDeactivate,              ///< 페어링 비활성화
            AdvertisingStart,               ///< 장치를 검색 가능한 상태로 변경
            AdvertisingStop,                ///< 장치를 검색 불가능한 상태로 변경
            TerminateConnection,            ///< 연결 종료
            ClearBondList,                  ///< 본딩된 장치 리스트 제거
            
            // 요청
            Request = 0x90,                 ///< 지정한 타입의 데이터 요청
            
            EndOfType
        };
    }
}
```


---
[Home](README.md)

