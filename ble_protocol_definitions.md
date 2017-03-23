***PETRONE / BLE / Protocol / Definitions***<br>
Modified : 2017.03.23

---

#### Petrone에서 사용하고 있는 정의들을 소개합니다.

---

## <a name="CommandType">Protocol::CommandType::Type</a>
CommandBase 구조체에서 commandType 변수에 사용합니다.

```cpp
namespace Protocol
{
    namespace CommandType
    {
        enum Type
        {
            None = 0,               // 이벤트 없음
            
            // 설정
            ModeVehicle = 0x10,     // 동작 모드 전환
            
            // 제어
            Coordinate = 0x20,      // 방위 기준 변경
            Trim,                   // 트림 변경
            FlightEvent,            // 비행 이벤트 실행
            DriveEvent,             // 주행 이벤트 실행
            Stop,                   // 정지
            
            ResetHeading = 0x50,    // 방향 초기화
            ClearGyroBiasAndTrim,   // 자이로 바이어스와 트림 설정 초기화
            ClearTrim,              // 트림 초기화
            
            // 요청
            Request = 0x90,         // 지정한 타입의 데이터 요청
            
            EndOfType
        };
    }
}
```


## <a name="ModeVehicle">System::ModeVehicle::Type</a>
CommandBase 구조체에서 option 변수에 사용합니다.

```cpp
namespace System
{
    namespace ModeVehicle
    {
        enum Type
        {
            None = 0,           // 없음
            
            Flight = 0x10,      // 비행(가드 포함)
            FlightNoGuard,      // 비행(가드 없음)
            FlightFPV,          // 비행(FPV)
            
            Drive = 0x20,       // 주행
            DriveFPV,           // 주행(FPV)
            
            EndOfType
        };
    }
    
}
```


## <a name="Coordinate">System::Coordinate::Type</a>
CommandBase 구조체에서 option 변수에 사용합니다.

```cpp
namespace System
{
    namespace Coordinate
    {
        enum Type
        {
            None = 0,           ///< 없음
            
            World,              ///< 고정 좌표계(Absolute)
            Local,              ///< 상대 좌표계(일반)
            
            EndOfType
        };
    }
}
```




## <a name="LightMode">Light::Mode::Type</a>
LED 모드 또는 이벤트 명령 시 동작 모드를 지정할 때 사용합니다.

```cpp
namespace Light
{
    namespace Mode
    {
        enum Type
        {
            None,
            
            EyeNone = 0x10,
            EyeHold,            // 지정한 색상을 계속 켬
            EyeMix,             // 순차적으로 LED 색 변경
            EyeFlicker,         // 깜빡임         
            EyeFlickerDouble,   // 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
            EyeDimming,         // 밝기 제어하여 천천히 깜빡임
            
            ArmNone = 0x40,     
            ArmHold,            // 지정한 색상을 계속 켬
            ArmMix,             // 순차적으로 LED 색 변경
            ArmFlicker,         // 깜빡임         
            ArmFlickerDouble,   // 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
            ArmDimming,         // 밝기 제어하여 천천히 깜빡임
            ArmFlow,            // 앞에서 뒤로 흐름           
            ArmFlowReverse,     // 뒤에서 앞으로 흐름 
            
            EndOfType
        };
    }
}
```



## <a name="LightColors">Light::Colors::Type</a>
LED 색상을 지정할 때 사용합니다.

```cpp
namespace Light
{
    namespace Colors
    {
        enum Type
        {
            AliceBlue,
            AntiqueWhite,
            Aqua,
            Aquamarine,
            Azure,
            Beige,
            Bisque,
            Black,
            BlanchedAlmond,
            Blue,
            BlueViolet,
            Brown,
            BurlyWood,
            CadetBlue,
            Chartreuse,
            Chocolate,
            Coral,
            CornflowerBlue,
            Cornsilk,
            Crimson,
            Cyan,
            DarkBlue,
            DarkCyan,
            DarkGoldenRod,
            DarkGray,
            DarkGreen,
            DarkKhaki,
            DarkMagenta,
            DarkOliveGreen,
            DarkOrange,
            DarkOrchid,
            DarkRed,
            DarkSalmon,
            DarkSeaGreen,
            DarkSlateBlue,
            DarkSlateGray,
            DarkTurquoise,
            DarkViolet,
            DeepPink,
            DeepSkyBlue,
            DimGray,
            DodgerBlue,
            FireBrick,
            FloralWhite,
            ForestGreen,
            Fuchsia,
            Gainsboro,
            GhostWhite,
            Gold,
            GoldenRod,
            Gray,
            Green,
            GreenYellow,
            HoneyDew,
            HotPink,
            IndianRed,
            Indigo,
            Ivory,
            Khaki,
            Lavender,
            LavenderBlush,
            LawnGreen,
            LemonChiffon,
            LightBlue,
            LightCoral,
            LightCyan,
            LightGoldenRodYellow,
            LightGray,
            LightGreen,
            LightPink,
            LightSalmon,
            LightSeaGreen,
            LightSkyBlue,
            LightSlateGray,
            LightSteelBlue,
            LightYellow,
            Lime,
            LimeGreen,
            Linen,
            Magenta,
            Maroon,
            MediumAquaMarine,
            MediumBlue,
            MediumOrchid,
            MediumPurple,
            MediumSeaGreen,
            MediumSlateBlue,
            MediumSpringGreen,
            MediumTurquoise,
            MediumVioletRed,
            MidnightBlue,
            MintCream,
            MistyRose,
            Moccasin,
            NavajoWhite,
            Navy,
            OldLace,
            Olive,
            OliveDrab,
            Orange,
            OrangeRed,
            Orchid,
            PaleGoldenRod,
            PaleGreen,
            PaleTurquoise,
            PaleVioletRed,
            PapayaWhip,
            PeachPuff,
            Peru,
            Pink,
            Plum,
            PowderBlue,
            Purple,
            RebeccaPurple,
            Red,
            RosyBrown,
            RoyalBlue,
            SaddleBrown,
            Salmon,
            SandyBrown,
            SeaGreen,
            SeaShell,
            Sienna,
            Silver,
            SkyBlue,
            SlateBlue,
            SlateGray,
            Snow,
            SpringGreen,
            SteelBlue,
            Tan,
            Teal,
            Thistle,
            Tomato,
            Turquoise,
            Violet,
            Wheat,
            White,
            WhiteSmoke,
            Yellow,
            YellowGreen,
            
            EndOfColor
        };
    }
}
```


---
[Home](README.md)

