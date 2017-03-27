***PETRONE / LINK / Protocol / Structs***<br>
Modified : 2017.03.27

---

#### 송신 데이터 예제를 보여드립니다.

---

<br>

## <a name="LinkModeBroadcast_Active">LinkModeBroadcast - Active</a>
LINK를 Active 모드로 변경할 때 사용하는 명령입니다. PC 또는 아두이노 보드에서 LINK 모듈과 통신을 할 때 가장 먼저 이 명령을 전송하면 LINK 모듈의 버튼을 두 번 누르지 않고도 페트론 연결 모드로 전환됩니다. Active 모드일 때 아두이노 펌웨어를 업데이트하면 Mute모드로 자동 전환되므로 모드 전환은 이 명령만 사용하시면 됩니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E0</td>
        <td>02</td>
        <td>83</td>
        <td>33</td>
    </tr>
</table>

<br>
<br>

## <a name="LinkSystemReset">LinkSystemReset</a>
LINK를 Soft Reset 할 때 사용하는 명령입니다. 동작 중 문제가 발생하였으나 시리얼 통신은 가능할 때 이 명령을 보내면 모듈을 리셋합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E1</td>
        <td>00</td>
        <td>F0</td>
        <td>20</td>
    </tr>
</table>

<br>
<br>

## <a name="LinkState">LinkState</a>
LINK 모듈의 현재 상태를 확인하고자 할 때 해당 데이터를 요청하는 명령입니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>90</td>
        <td>E0</td>
        <td>B6</td>
        <td>E6</td>
    </tr>
</table>

<br>
<br>

## <a name="LinkDiscoverStart">LinkDiscoverStart</a>
BLE 장치를 검색할 때 사용하는 명령입니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E2</td>
        <td>00</td>
        <td>A3</td>
        <td>75</td>
    </tr>
</table>

<br>
<br>

## <a name="Connect_0">Connect 0</a>
Discover Start를 통해 검색된 장치 중 0번 장치에 연결할 때 사용합니다. 6번째 바이트는 연결할 장치의 인덱스를 의미합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E4</td>
        <td>00</td>
        <td>05</td>
        <td>DF</td>
    </tr>
</table>

<br>
<br>

## <a name="Connect_1">Connect 1</a>
Discover Start를 통해 검색된 장치 중 1번 장치에 연결할 때 사용합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E4</td>
        <td>01</td>
        <td>24</td>
        <td>CF</td>
    </tr>
</table>

<br>
<br>

## <a name="Connect_2">Connect 2</a>
Discover Start를 통해 검색된 장치 중 2번 장치에 연결할 때 사용합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E4</td>
        <td>02</td>
        <td>47</td>
        <td>FF</td>
    </tr>
</table>

<br>
<br>

## <a name="Connect_1">Disconnect</a>
연결을 해제할 때 사용하는 명령입니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E5</td>
        <td>00</td>
        <td>34</td>
        <td>EC</td>
    </tr>
</table>

<br>
<br>

## <a name="RSSI_polling_start">RSSI polling start</a>
현재 연결된 장치의 RSSI 값 스캔을 시작할 때 사용하는 명령입니다. 여기에서는 6번째 바이트의 값을 02로 지정하였습니다. 이때에는 이 값에 100을 곱한 200ms 주기로 RSSI 값을 스캔합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E6</td>
        <td>02</td>
        <td>25</td>
        <td>99</td>
    </tr>
</table>

<br>
<br>

## <a name="RSSI_polling_stop">RSSI polling stop</a>
현재 연결된 장치의 RSSI 값 스캔을 중단할 때 사용하는 명령입니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E7</td>
        <td>00</td>
        <td>56</td>
        <td>8A</td>
    </tr>
</table>

<br>
<br>

## <a name="Address">Address</a>
LINK 모듈과 연결된 PETRONE의 장치 주소를 요청하는 명령입니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>90</td>
        <td>30</td>
        <td>CB</td>
        <td>2D</td>
    </tr>
</table>

<br>
<br>

## <a name="LED_Dimming_Yellow">LED Dimming - Yellow</a>
PETRONE과 연결된 경우, 아래의 명령을 보내면 프로펠러 쪽 LED들이 노란색으로 밝아졌다가 어두워지는 동작을 반복합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="3">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>20</td>
        <td>03</td>
        <td>45</td>
        <td>8B</td>
        <td>07</td>
        <td>B0</td>
        <td>D2</td>
    </tr>
</table>

<br>
<br>

## <a name="LED_Dimming_Cyan">LED Dimming - Cyan</a>
PETRONE과 연결된 경우, 아래의 명령을 보내면 프로펠러 쪽 LED들이 하늘색으로 밝아졌다가 어두워지는 동작을 반복합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="3">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>20</td>
        <td>03</td>
        <td>45</td>
        <td>72</td>
        <td>07</td>
        <td>E9</td>
        <td>7B</td>
    </tr>
</table>

<br>
<br>

## <a name="LED_Dimming_Red">LED Dimming - Red</a>
PETRONE과 연결된 경우, 아래의 명령을 보내면 프로펠러 쪽 LED들이 빨간색으로 밝아졌다가 어두워지는 동작을 반복합니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
        <td>7</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="3">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>20</td>
        <td>03</td>
        <td>45</td>
        <td>72</td>
        <td>07</td>
        <td>E9</td>
        <td>7B</td>
    </tr>
</table>







<br>

---
[Home](../../README.md)
