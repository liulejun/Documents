***PETRONE / LINK / Protocol / Structs***<br>
Modified : 2017.03.27

---

#### 데이터 송수신 시에 사용하는 구조체들을 소개합니다.

---

<br>

## <a name="LinkState ">Protocol::LinkState </a>
PETRONE LINK 모듈의 동작 모드
```cpp
namespace Protocol
{
    struct LinkState 
    {
        u8      modeLink;           // 링크 동작 모드
        u8      modeLinkBroadcast;
    };
}
```
- modeLink : [System::ModeLink::Type](definitions.md#ModeLink)
- modeLinkBroadcast : [System::ModeLinkBroadcast::Type](definitions.md#ModeLinkBroadcast)


<br>
<br>


## <a name="LinkEvent">Protocol::LinkEvent</a>
PETRONE LINK 모듈에서 발생한 이벤트
```cpp
namespace Protocol
{
    struct LinkEvent
        u8      eventLink;          // 링크 이벤트
        u8      eventResult;        // 링크 이벤트 리턴 값
    };
}
```
- eventLink : [System::EventLink::Type](definitions.md#EventLink)


<br>
<br>


## <a name="LinkEventAddress">Protocol::LinkEventAddress</a>
PETRONE LINK 모듈에서 발생한 이벤트 및 관련 장치의 주소 포함
```cpp
namespace Protocol
{
    struct LinkEventAddress
    {
        u8      eventLink;          // 링크 이벤트
        u8      eventResult;        // 링크 이벤트 리턴 값
        u8      address[6];         // 장치 주소
    };
}

- eventLink : [System::EventLink::Type](definitions.md#EventLink)


<br>
<br>


## <a name="LinkRssi">Protocol::LinkRssi</a>
링크와 연결된 장치의 RSSI
```cpp
namespace Protocol
{
    struct LinkRssi
    {
        s8      rssi;               // 링크와 연결된 장치의 RSSI
    };
}
```


<br>
<br>


## <a name="LinkDiscoveredDevice">Protocol::LinkDiscoveredDevice</a>
SCAN 명령을 내리면 LINK 모듈이 검색된 장치 정보를 LinkDiscoveredDevice에 담아서 전송합니다.
```cpp
namespace Protocol
{
    struct LinkDiscoveredDevice
    {
        u8      index;              // index
        u8      address[6];         // Address of the advertisement or SCAN_RSP
        u8      name[20];           // Name of the advertisement or SCAN_RSP
        s8      rssi;               // Advertisement or SCAN_RSP RSSI
    };
}
```


<br>
<br>


## <a name="LinkPasscode">Protocol::LinkPasscode</a>
장치 비밀번호 설정
```cpp
namespace Protocol
{
    struct LinkPasscode
    {
        u32     passcode;           // 장치 비밀 번호
    };
}
```
PETRONE과 페어링이 필요한 경우에 LinkPasscode를 통해 먼저 페어링 비밀번호를 지정합니다. 이후 장치와 연결할 때 페어링 과정에서 필요한 비밀 번호를 자동으로 입력합니다. 비밀 번호는 플래시 메모리에 저장합니다.


<br>

---
[Home](../../../README.md)

