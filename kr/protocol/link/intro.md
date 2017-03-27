***PETRONE / LINK / Protocol / Intro***<br>
Modified : 2017.03.27

---

<br>

# 1. PETRONE LINK 소개

**PETRONE LINK**(이하 LINK)는 PETRONE과의 연결 및 제어를 도와주는 통신 모듈입니다. PETRONE과 LINK 사이에는 Bluetooth Low Energy(이하 BLE)를 사용하여 통신하지만, LINK 사용자는 BLE에 대해 신경 쓸 필요 없이 시리얼 통신만으로 PETRONE과 연결하여 제어할 수 있습니다.


<br>
<br>


# 2. 전송 데이터 구조

**LINK** 장치와 통신을 할 때의 데이터 블럭 구성은 다음과 같습니다.

<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>...</td>
        <td>N-1</td>
        <td>N</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0x0A</td>
        <td>0x55</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
    </tr>
</table>

각 항목에 대한 설명은 다음과 같습니다.


|영역        | 설명                                                                                                |
|:-----------|:----------------------------------------------------------------------------------------------------|
| Start code | 데이터 전송 시작을 알림                                                                             |
| Header     | 헤더 뒤에 이어지는 데이터의 형식과 길이                                                             |
| Data       | 전송할 데이터                                                                                       |
| CRC16      | Header와 Data가 정상적으로 전달되었는지 판별<br>http://www.menie.org/georges/embedded/crc16.html    |


<br>
<br>


# 3. 사용 시 주의사항

- LINK 모듈을 제어할 때에는 [Command(0x11)](../structs.md#Command)를 주로 사용합니다.

- PETRONE 제어와 관련된 부분에 관해서는 PETRONE 문서를 참고하시기 바랍니다. BLE를 통해 전달하는 것과의 차이점은 LINK를 통해 PETRONE을 제어하려고 할 때에는 [Start code + DataType + DataLength + Data + CRC16] 형태로 전송해야 합니다. 반면 BLE를 통해 데이터를 전송할 때에는 [DataType + Data] 형태로 데이터를 전송합니다.

- LINK 모듈에 데이터를 전송하는 경우 몇 가지 명령을 제외하고 대부분 Ack 데이터가 반송됩니다.

- LINK 모듈은 Active 모드일 때 LINK의 동작 모드 변경을 통신으로 알려줍니다.

- 장치 스캔은 1.6초 동안 동작하며 스캔이 끝날 때 까지는 시리얼 통신을 처리하지 못합니다.


<br>
<br>


# 4. 시리얼 통신 설정


|영역        | 설정값    |
|:-----------|:----------|
| Baud Rate  | 115200    |
| Parity     | None      |
| Data Bits  | 8         |
| Stop Bits  | 1         |


<br>
<br>


# 5. 드라이버 설치

LINK 모듈은 시리얼 통신용으로 Silicon Labs사의 CP2104를 사용하고 있습니다. 윈도우에서 자동으로 USB 드라이버를 설치하지 못할 경우, 아래의 사이트를 방문하여 OS에 맞는 드라이버를 받아서 설치하시기 바랍니다.

https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx

<br>

---
[Home](../../../README.md)
