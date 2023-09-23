#include "s.h"
struct AdtsHeader {
    unsigned syncword :12;  //12 bit 同步字 '1111 1111 1111'，一个ADTS帧的开始
    unsigned id:1;        //1 bit 0代表MPEG-4, 1代表MPEG-2。
    unsigned layer:2;     //2 bit 必须为0
    unsigned protectionAbsent:1;  //1 bit 1代表没有CRC，0代表有CRC
    unsigned profile:1;           //1 bit AAC级别（MPEG-2 AAC中定义了3种profile，MPEG-4 AAC中定义了6种profile）
    unsigned samplingFreqIndex:4; //4 bit 采样率
    unsigned privateBit:1;        //1bit 编码时设置为0，解码时忽略
    unsigned channelCfg:3;        //3 bit 声道数量
    unsigned originalCopy:1;      //1bit 编码时设置为0，解码时忽略
    unsigned home:1;               //1 bit 编码时设置为0，解码时忽略

    unsigned copyrightIdentificationBit:1;   //1 bit 编码时设置为0，解码时忽略
    unsigned copyrightIdentificationStart:1; //1 bit 编码时设置为0，解码时忽略
    unsigned aacFrameLength:13;               //13 bit 一个ADTS帧的长度包括ADTS头和AAC原始流
    unsigned adtsBufferFullness:11;           //11 bit 缓冲区充满度，0x7FF说明是码率可变的码流，不需要此字段。CBR可能需要此字段，不同编码器使用情况不同。这个在使用音频编码的时候需要注意。

    /* number_of_raw_data_blocks_in_frame
     * 表示ADTS帧中有number_of_raw_data_blocks_in_frame + 1个AAC原始帧
     * 所以说number_of_raw_data_blocks_in_frame == 0
     * 表示说ADTS帧中有一个AAC数据块并不是说没有。(一个AAC原始帧包含一段时间内1024个采样及相关数据)
     */
    unsigned numberOfRawDataBlockInFrame:2; //2 bit
};

int main(){

    cout << sizeof(AdtsHeader);

    return 0;
}