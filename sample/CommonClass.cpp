//
//  CommonClass.cpp
//  FPVPlugin
//
//  Created by byrobot on 2016. 7. 11..
//  Copyright © 2016년 이각규. All rights reserved.
//

#include "CommonClass.hpp"
#include <stdlib.h>

namespace ByrobotProtocol {
    static unsigned short crc16table[256] = {
        0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
        0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
        0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
        0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
        0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
        0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
        0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
        0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
        0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
        0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
        0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
        0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
        0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
        0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
        0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
        0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
        0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
        0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
        0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
        0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
        0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
        0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
        0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
        0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
        0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
        0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
        0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
        0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
        0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
        0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
        0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
        0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
    };
    
    //// CRC16 class
    uint16_t CRC16::getCRC(const uint8_t* dataArray, int dataLength)
    {
        int i;
        uint16_t crc = 0;
        
        for (i = 0; i < dataLength; i++)
            crc = (uint16_t)((crc << 8) ^ crc16table[((crc >> 8) ^ dataArray[i]) & 0x00FF]);
        
        return crc;
    }

    uint16_t CRC16::getCRC(const uint8_t* header, int headerLength, const uint8_t* dataArray, int dataLength)
    {
        int i;
        uint16_t crc = 0;
        
        // Header
        for (i = 0; i < headerLength; i++)
            crc = (uint16_t)((crc << 8) ^ crc16table[((crc >> 8) ^ header[i]) & 0x00FF]);
        
        // Data
        for (i = 0; i < dataLength; i++)
            crc = (uint16_t)((crc << 8) ^ crc16table[((crc >> 8) ^ dataArray[i]) & 0x00FF]);
        
        return crc;
    }
    
    //// CSerializer class
    CSerializer::CSerializer() : m_counter(0)
    {
    }
    
    int CSerializer::GetCounter()
    {
        return m_counter;
    }
    
    bool CSerializer::Add(uint8_t* target, bool value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)value;
        return true;
    }
    bool CSerializer::Add(uint8_t* target, uint8_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = value;
        return true;
    }
    bool CSerializer::Add(uint8_t* target, int8_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, int16_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, uint16_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, int32_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 16) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 24) & 0xff);
        return true;
    }
    
    bool CSerializer::Add(uint8_t* target, uint32_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 16) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 24) & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, int64_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 16) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 24) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 32) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 40) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 48) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 54) & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, uint64_t value)
    {
        if( target == NULL ) return false;
        
        target[m_counter++] = (uint8_t)(value & 0xff);
        target[m_counter++] = (uint8_t)((value >> 8) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 16) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 24) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 32) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 40) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 48) & 0xff);
        target[m_counter++] = (uint8_t)((value >> 54) & 0xff);
        return true;
    }
    bool CSerializer::Add(uint8_t* target, const uint8_t* value, int length)
    {
        if( target == NULL ) return false;
        
        for( int i = 0; i < length; ++i) {
            target[m_counter++] = (uint8_t)(value[i] & 0xff);
        }
        return true;
    }
    
    //// CExtractor class
    CExtractor::CExtractor(uint8_t* data) : m_counter(0), m_dataArray(NULL)
    {
        if( data != NULL) m_dataArray = data;
    }
    
    int CExtractor::GetCounter()
    {
        return m_counter;
    }
    
    bool CExtractor::GetBool()
    {
        if( m_dataArray == NULL) return false;
        return (bool)m_dataArray[m_counter++];
    }
    char CExtractor::GetChar()
    {
        if( m_dataArray == NULL) return 0;
        return m_dataArray[m_counter++];
    }
    short CExtractor::GetShort()
    {
        if( m_dataArray == NULL) return 0;
        short ret = 0;
        ret = m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        m_counter += 2;
        
        return ret;
    }
    unsigned short CExtractor::GetUShort()
    {
        if( m_dataArray == NULL) return 0;
        unsigned short ret = 0;
        ret = m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        m_counter += 2;
        
        return ret;
    }
    
    int CExtractor::GetInt()
    {
        if( m_dataArray == NULL) return 0;
        int ret = 0;
        ret = m_dataArray[m_counter+3];
        ret = ret << 8 | m_dataArray[m_counter+2];
        ret = ret << 8 | m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        m_counter += 4;
        
        return ret;
    }
    unsigned int CExtractor::GetUInt()
    {
        if( m_dataArray == NULL) return 0;
        unsigned int ret = 0;
        ret = m_dataArray[m_counter+3];
        ret = ret << 8 | m_dataArray[m_counter+2];
        ret = ret << 8 | m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        m_counter += 4;
        
        return ret;
    }
    long long CExtractor::GetInt64()
    {
        if( m_dataArray == NULL) return 0;
        long long ret = 0;
        ret = m_dataArray[m_counter+7];
        ret = ret << 8 | m_dataArray[m_counter+6];
        ret = ret << 8 | m_dataArray[m_counter+5];
        ret = ret << 8 | m_dataArray[m_counter+4];
        ret = ret << 8 | m_dataArray[m_counter+3];
        ret = ret << 8 | m_dataArray[m_counter+2];
        ret = ret << 8 | m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        
        m_counter += 8;
        return ret;
    }
    unsigned long long CExtractor::GetUInt64()
    {
        if( m_dataArray == NULL) return 0;
        unsigned long long ret = 0;
        ret = m_dataArray[m_counter+7];
        ret = ret << 8 | m_dataArray[m_counter+6];
        ret = ret << 8 | m_dataArray[m_counter+5];
        ret = ret << 8 | m_dataArray[m_counter+4];
        ret = ret << 8 | m_dataArray[m_counter+3];
        ret = ret << 8 | m_dataArray[m_counter+2];
        ret = ret << 8 | m_dataArray[m_counter+1];
        ret = ret << 8 | m_dataArray[m_counter];
        
        m_counter += 8;
        
        return ret;
    }
    
    //// CCommandBase class
    CCommandBase::CCommandBase() : m_size(2)
    {
        
    }
    
    int CCommandBase::GetSize()
    {
        return m_size;
    }
    
    CCommandBase* CCommandBase::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CCommandBase * command = new CCommandBase();
        CExtractor * extractor = new CExtractor(dataArray);
        command->commandType = (CommandType::Enum)extractor->GetChar();
        
        return command;
    }
    
    const uint8_t* CCommandBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)commandType);
        serializer->Add(dataArray, (uint8_t)option);
        return dataArray;
    }
    
    
    //// CRequest class
    CRequest::CRequest() : m_size(1)
    {
    }
    
    int CRequest::GetSize()
    {
        return m_size;
    }
    
    const CRequest* CRequest::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        CRequest * request = new CRequest();
        
        CExtractor * extractor = new CExtractor(dataArray);
        request->dataType = (DataType::Enum)extractor->GetChar();
        
        return request;
    }
    
    const uint8_t* CRequest::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)dataType);
        return dataArray;
    }
    
    const uint8_t* CRequest::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Request);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CRequest::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Request);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    
    //// CControl class
    CControl::CControl() : m_size(4)
    {
        roll = 0;
        pitch = 0;
        yaw = 0;
        throttle = 0;
    }
    
    const uint8_t* CControl::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, roll);
        serializer->Add(dataArray, pitch);
        serializer->Add(dataArray, yaw);
        serializer->Add(dataArray, throttle);
        return dataArray;
    }
    
    const uint8_t* CControl::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Control);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CControl::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Control);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CControl::GetSize()
    {
        return m_size;
    }
    
    
    /// Command class
    CCommand::CCommand()
    {
        command = new CCommandBase();
        m_size = command->GetSize();
    }
    
    
    const uint8_t* CCommand::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, command->ToArray(), command->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CCommand::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Command);
        serializer->Add(dataArray, ToArray(), GetSize());
        return dataArray;
    }
    
    const uint8_t* CCommand::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Command);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CCommand::GetSize()
    {
        return m_size;
    }
    
    
    /// CCommand2 class
    CCommand2::CCommand2()
    {
        command1 = new CCommandBase();
        command2 = new CCommandBase();
        m_size = command1->GetSize() + command2->GetSize();
    }
    
    
    const uint8_t* CCommand2::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, command1->ToArray(), command1->GetSize());
        serializer->Add(dataArray, command2->ToArray(), command2->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CCommand2::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Command2);
        serializer->Add(dataArray, ToArray(), GetSize());
        return dataArray;
    }
    
    const uint8_t* CCommand2::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::Command2);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CCommand2::GetSize()
    {
        return m_size;
    }
    
    //// CUpdateLookupTarget class
    CUpdateLookupTarget::CUpdateLookupTarget() : m_size(4)
    {
        
    }
    
    CUpdateLookupTarget* CUpdateLookupTarget::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CUpdateLookupTarget * info = new CUpdateLookupTarget();
        CExtractor * extractor = new CExtractor(dataArray);
        info->deviceType = (Firmware::DeviceType)extractor->GetUInt();
        return info;
    }
    const uint8_t* CUpdateLookupTarget::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint32_t)deviceType);
        
        return dataArray;
    }
    const uint8_t* CUpdateLookupTarget::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::UpdateLookupTarget);
        serializer->Add(dataArray, ToArray(), GetSize());
        return dataArray;
    }
    const uint8_t* CUpdateLookupTarget::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::UpdateLookupTarget);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), GetSize());
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CUpdateLookupTarget::GetSize()
    {
        return m_size;
    }
    
    //// CUpdateInformation class
    CUpdateInformation::CUpdateInformation()  : m_size(11)
    {
        
    }
    
    CUpdateInformation* CUpdateInformation::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CUpdateInformation * info = new CUpdateInformation();
        CExtractor * extractor = new CExtractor(dataArray);
        info->modeUpdate = (ModeUpdate::Enum)extractor->GetChar();
        info->deviceType = (Firmware::DeviceType)extractor->GetUInt();
        info->imageType = (Firmware::ImageType)extractor->GetChar();
        info->imageVersion = extractor->GetUShort();
        
        info->year = extractor->GetChar();
        info->month = extractor->GetChar();
        info->day = extractor->GetChar();
        return info;
    }

    //// CUpdate class
    CUpdate::CUpdate() : m_size(18)
    {
        dataBlock = new uint8_t[16];
    }

    const uint8_t* CUpdate::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();

        serializer->Add(dataArray, indexBlock);
        serializer->Add(dataArray, dataBlock, 16);

        return dataArray;
    }
    const uint8_t* CUpdate::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();

        serializer->Add(dataArray, (uint8_t)DataType::Update);
        serializer->Add(dataArray, ToArray(), m_size);

        return dataArray;
    }
    const uint8_t* CUpdate::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();

        serializer->Add(dataArray, (uint8_t)DataType::Update);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);


        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();

        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));

        return sendData;
    }
    int CUpdate::GetSize()
    {
        return m_size;
    }
    
    //// CLedModeBase class
    CLedModeBase::CLedModeBase() : m_size(3)
    {
        
    }
    
    int CLedModeBase::GetSize()
    {
        return m_size;
    }
    
    CLedModeBase* CLedModeBase::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CLedModeBase * ledModeBase = new CLedModeBase();
        CExtractor * extractor = new CExtractor(dataArray);
        ledModeBase->mode = (Light::Mode::Enum)extractor->GetChar();
        ledModeBase->colors = (Light::Colors::Enum)extractor->GetChar();
        ledModeBase->interval = extractor->GetChar();
        
        return ledModeBase;
    }
    
    const uint8_t* CLedModeBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)mode);
        serializer->Add(dataArray, (uint8_t)colors);
        serializer->Add(dataArray, interval);
        return dataArray;
    }
    
    
    //// CLedMode class
    CLedMode::CLedMode()
    {
        ledMode = new CLedModeBase();
        m_size = ledMode->GetSize();
    }
    
    const uint8_t* CLedMode::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledMode->ToArray(), ledMode->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CLedMode::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedMode);
        serializer->Add(dataArray, ledMode->ToArray(), ledMode->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CLedMode::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedMode);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ledMode->ToArray(), ledMode->GetSize());
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CLedMode::GetSize()
    {
        return m_size;
    }
    
    
    //// CLedMode2 class
    CLedMode2::CLedMode2()
    {
        ledMode1 = new CLedModeBase();
        ledMode2 = new CLedModeBase();
        m_size = ledMode1->GetSize() + ledMode2->GetSize();
    }
    
    const uint8_t* CLedMode2::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledMode1->ToArray(), ledMode1->GetSize());
        serializer->Add(dataArray, ledMode2->ToArray(), ledMode2->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CLedMode2::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedMode2);
        serializer->Add(dataArray, ledMode1->ToArray(), ledMode1->GetSize());
        serializer->Add(dataArray, ledMode2->ToArray(), ledMode2->GetSize());
        
        return dataArray;
    }
    
    const uint8_t* CLedMode2::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedMode2);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ledMode1->ToArray(), ledMode1->GetSize());
        serializer->Add(dataArray, ledMode2->ToArray(), ledMode2->GetSize());
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CLedMode2::GetSize()
    {
        return m_size;
    }
    
    
    //// CLedEventBase class
    CLedEventBase::CLedEventBase() : m_size(4)
    {
        
    }
    
    CLedEventBase* Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CLedEventBase * ledEventBase = new CLedEventBase();
        CExtractor * extractor = new CExtractor(dataArray);
        ledEventBase->mode = (Light::Mode::Enum)extractor->GetChar();
        ledEventBase->colors = (Light::Colors::Enum)extractor->GetChar();
        ledEventBase->interval = extractor->GetChar();
        ledEventBase->repeat = extractor->GetChar();
        
        return ledEventBase;
    }
    
    const uint8_t* CLedEventBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)mode);
        serializer->Add(dataArray, (uint8_t)colors);
        serializer->Add(dataArray, (uint8_t)interval);
        serializer->Add(dataArray, (uint8_t)repeat);
        return dataArray;
    }
    
    int CLedEventBase::GetSize()
    {
        return m_size;
    }
    
    CLedModeColorBase::CLedModeColorBase() : m_size(5)
    {
        
    }
    
    CLedModeColorBase* CLedModeColorBase::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CLedModeColorBase * ledModeBase = new CLedModeColorBase();
        CExtractor * extractor = new CExtractor(dataArray);
        ledModeBase->mode = (Light::Mode::Enum)extractor->GetChar();
        ledModeBase->red = extractor->GetChar();
        ledModeBase->green = extractor->GetChar();
        ledModeBase->blue = extractor->GetChar();
        ledModeBase->interval = extractor->GetChar();
        
        return ledModeBase;
    }
    const uint8_t* CLedModeColorBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)mode);
        serializer->Add(dataArray, (uint8_t)red);
        serializer->Add(dataArray, (uint8_t)green);
        serializer->Add(dataArray, (uint8_t)blue);
        serializer->Add(dataArray, (uint8_t)interval);
        return dataArray;
    }
    
    int CLedModeColorBase::GetSize()
    {
        return m_size;
    }
    
    CLedModeColor::CLedModeColor()
    {
        ledModeColorBase = new CLedModeColorBase();
        m_size = ledModeColorBase->GetSize();
    }
    
    const uint8_t* CLedModeColor::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledModeColorBase->ToArray(), ledModeColorBase->GetSize());
        return dataArray;
    }
    const uint8_t* CLedModeColor::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedModeColor);
        serializer->Add(dataArray, ledModeColorBase->ToArray(), ledModeColorBase->GetSize());
        
        return dataArray;
    }
    const uint8_t* CLedModeColor::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedModeColor);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ledModeColorBase->ToArray(), ledModeColorBase->GetSize());
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    int CLedModeColor::GetSize()
    {
        return m_size;
    }
    
    CLedModeColor2::CLedModeColor2()
    {
        ledModeColorBase1 = new CLedModeColorBase();
        ledModeColorBase2 = new CLedModeColorBase();
        m_size = ledModeColorBase1->GetSize() + ledModeColorBase2->GetSize();
    }
    
    const uint8_t* CLedModeColor2::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledModeColorBase1->ToArray(), ledModeColorBase1->GetSize());
        serializer->Add(dataArray, ledModeColorBase2->ToArray(), ledModeColorBase2->GetSize());
        return dataArray;
    }
    const uint8_t* CLedModeColor2::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedModeColor2);
        serializer->Add(dataArray, ToArray(), m_size);
        
        return dataArray;
    }
    const uint8_t* CLedModeColor2::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedModeColor2);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    int CLedModeColor2::GetSize()
    {
        return m_size;
    }
    
    //// CLedEventCommand class
    CLedEventCommand::CLedEventCommand()
    {
        ledCommand = new CCommandBase();
        ledEvent = new CLedEventBase();
        m_size = ledCommand->GetSize() + ledEvent->GetSize();
    }
    
    const uint8_t* CLedEventCommand::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledEvent->ToArray(), ledEvent->GetSize());
        serializer->Add(dataArray, ledCommand->ToArray(), ledCommand->GetSize());
        
        return dataArray;
    }
    const uint8_t* CLedEventCommand::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedEventCommand);
        serializer->Add(dataArray, ToArray(), m_size);
        
        return dataArray;
    }
    const uint8_t* CLedEventCommand::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedEventCommand);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    int CLedEventCommand::GetSize()
    {
        return m_size;
    }
    
    
    //// CLedEventCommandIr class
    CLedEventCommandIr::CLedEventCommandIr()
    {
        ledCommand = new CCommandBase();
        ledEvent = new CLedEventBase();
        m_size = ledCommand->GetSize() + ledEvent->GetSize() + 4;
    }
    
    const uint8_t* CLedEventCommandIr::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, ledEvent->ToArray(), ledEvent->GetSize());
        serializer->Add(dataArray, ledCommand->ToArray(), ledCommand->GetSize());
        serializer->Add(dataArray, irData);
        
        return dataArray;
    }
    const uint8_t* CLedEventCommandIr::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedEventCommandIr);
        serializer->Add(dataArray, ToArray(), m_size);
        
        return dataArray;
    }
    const uint8_t* CLedEventCommandIr::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::LedEventCommand);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    int CLedEventCommandIr::GetSize()
    {
        return m_size;
    }
    
    //// CState class
    CState::CState() : m_size(7)
    {
        
    }
    
    int CState::GetSize()
    {
        return m_size;
    }
    
    CState* CState::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CState * state = new CState();
        CExtractor * extractor = new CExtractor(dataArray);
        state->modePetrone = (ModePetrone::Enum)extractor->GetChar();
        state->modeVehicle = (ModeVehicle::Enum)extractor->GetChar();
        state->modeFlight = (ModeFlight::Enum)extractor->GetChar();
        state->modeDrive = (ModeDrive::Enum)extractor->GetChar();
        state->sensorOrientation = (SensorOrientation::Enum)extractor->GetChar();
        state->coordinate = (Coordinate::Enum)extractor->GetChar();
        state->battery = extractor->GetChar();
        
        return state;
    }
    
    //// CTrimFlightBase
    CTrimFlightBase::CTrimFlightBase() : m_size(8)
    {
        
    }
    
    const uint8_t* CTrimFlightBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, roll);
        serializer->Add(dataArray, pitch);
        serializer->Add(dataArray, yaw);
        serializer->Add(dataArray, throttle);
        
        return dataArray;
    }
    
    int CTrimFlightBase::GetSize()
    {
        return m_size;
    }
    
    //// CTrimDriveBase
    CTrimDriveBase::CTrimDriveBase() : m_size(2)
    {
        
    }
    
    const uint8_t* CTrimDriveBase::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, wheel);
        
        return dataArray;
    }
    
    int CTrimDriveBase::GetSize()
    {
        return m_size;
    }
        
    //// CTrimFlight class
    CTrimFlight* CTrimFlight::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CTrimFlight * trim = new CTrimFlight();
        CExtractor * extractor = new CExtractor(dataArray);
        trim->roll = extractor->GetShort();
        trim->pitch = extractor->GetShort();
        trim->yaw = extractor->GetShort();
        trim->throttle = extractor->GetShort();
        
        return trim;
    }
    
    //// CTrimDrive class
    CTrimDrive* CTrimDrive::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CTrimDrive * trim = new CTrimDrive();
        CExtractor * extractor = new CExtractor(dataArray);
        trim->wheel = extractor->GetShort();
        
        return trim;
    }
    
    
    //// CTrimAll class
    CTrimAll::CTrimAll()
    {
        m_size = flight.GetSize() + drive.GetSize();
    }
    
    CTrimAll* CTrimAll::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CTrimAll * info = new CTrimAll();
        
        CExtractor * extractor = new CExtractor(dataArray);
        info->flight.roll = (int16_t)extractor->GetShort();
        info->flight.pitch = (int16_t)extractor->GetShort();
        info->flight.yaw = (int16_t)extractor->GetShort();
        info->flight.throttle = (int16_t)extractor->GetShort();
        info->drive.wheel = (int16_t)extractor->GetShort();
        
        return info;
    }
    
    int CTrimAll::GetSize()
    {
        return m_size;
    }
    const uint8_t* CTrimAll::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, flight.ToArray(), flight.GetSize());
        serializer->Add(dataArray, drive.ToArray(), drive.GetSize());
        
        return dataArray;
    }
    const uint8_t* CTrimAll::ToTransferDataBlock()
    {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::TrimAll);
        serializer->Add(dataArray, ToArray(), m_size);
        
        return dataArray;
    }
    const uint8_t* CTrimAll::ToTransferDataBlockWifi()
    {
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::TrimAll);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    //// CFlightInfo
    CFlightInfo::CFlightInfo() : m_size(14)
    {
        
    }
    const uint8_t* CFlightInfo::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, time);
        serializer->Add(dataArray, takeoff);
        serializer->Add(dataArray, landing);
        serializer->Add(dataArray, accident);
        
        return dataArray;
    }
    
    CFlightInfo* CFlightInfo::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CFlightInfo * info = new CFlightInfo();
        CExtractor * extractor = new CExtractor(dataArray);
        info->time = (uint64_t)extractor->GetUInt64();
        info->takeoff = (uint16_t)extractor->GetUShort();
        info->landing = (uint16_t)extractor->GetUShort();
        info->accident = (uint16_t)extractor->GetUShort();
        
        return info;
    }
    
    int CFlightInfo::GetSize()
    {
        return m_size;
    }
    
    CDriveInfo::CDriveInfo() : m_size(10)
    {
        
    }
    
    const uint8_t* CDriveInfo::ToArray()
    {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, time);
        serializer->Add(dataArray, accident);
        
        return dataArray;
    }
    
    CDriveInfo* CDriveInfo::Parse(uint8_t* dataArray)
    {
        if( dataArray == NULL ) return NULL;
        
        CDriveInfo * info = new CDriveInfo();
        CExtractor * extractor = new CExtractor(dataArray);
        info->time = (uint64_t)extractor->GetUInt64();
        info->accident = (uint16_t)extractor->GetUShort();
        
        return info;
    }
    
    int CDriveInfo::GetSize()
    {
        return m_size;
    }
    
    //// CIRMessage class
    CIRMessage::CIRMessage() : m_size(5) {
        
    }
    
    CIRMessage* CIRMessage::Parse(uint8_t* dataArray) {
        
        if( dataArray == NULL ) return NULL;
        
        CIRMessage * message = new CIRMessage();
        CExtractor * extractor = new CExtractor(dataArray);
        message->direction = (Direction::Enum)extractor->GetChar();
        message->irData = (uint32_t)extractor->GetUInt();
        
        return message;
    }
    
    const uint8_t* CIRMessage::ToArray() {
        uint8_t* dataArray = new uint8_t[m_size];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, direction);
        serializer->Add(dataArray, irData);
        
        return dataArray;
    }
    
    const uint8_t* CIRMessage::ToTransferDataBlock() {
        uint8_t* dataArray = new uint8_t[m_size+1];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::IrMessage);
        serializer->Add(dataArray, ToArray(), m_size);
        
        return dataArray;
    }
    const uint8_t* CIRMessage::ToTransferDataBlockWifi() {
        
        uint8_t* dataArray = new uint8_t[m_size+2];
        CSerializer *serializer = new CSerializer();
        
        serializer->Add(dataArray, (uint8_t)DataType::IrMessage);
        serializer->Add(dataArray, (uint8_t)m_size);
        serializer->Add(dataArray, ToArray(), m_size);
        
        
        uint8_t* sendData = new uint8_t[m_size+2+4];
        CSerializer *sendSerial = new CSerializer();
        
        sendSerial->Add(sendData, (uint8_t)0x0a);
        sendSerial->Add(sendData, (uint8_t)0x55);
        sendSerial->Add(sendData, dataArray, m_size+2);
        sendSerial->Add(sendData, CRC16::getCRC(dataArray, m_size+2));
        
        return sendData;
    }
    
    int CIRMessage::GetSize() {
        return m_size;  
    }
    
};
