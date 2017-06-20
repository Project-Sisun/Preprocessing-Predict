/*
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
};

#include <stdio.h>


const char *uri = "rtsp://admin:1234@192.168.0.200:554/video1";
AVFormatContext *pFormatCtx = NULL;
AVCodecContext *pCodecCtx = NULL;
AVCodec *pCodec = NULL;

int init_rtsp() {

    // it must set to setDataSource for play.
    // avformat_open_input 메서드가 filename을 const char 의 pointer type으로 parameter를 받으므로 다음의 과정이 필요.

    if (uri == NULL) {
        printf("Please set the DataSource: ffmpeg_test\n");
        return -1;
    } else {
        printf("rtsp set source url>> %s\n", uri);
    }



*/
/*------------ 라이브러리 초기화 단계 ------------*//*



    // ffmpeg에서 지원되는 모든 Demuxer, Muxer, Protocol 및 Codec 등을 사용할 수 있도록 등록.
    // get muxer, demuxer and protocol definitions.
    // Initialize libavformat and register all the muxers, demuxers and protocols. - in FFmpeg Guide
    av_register_all();

    // network 사용을 위한 추가 초기화 작업을 수행.
    // 종료 시 해제 함수 avformat_network_deinit(); 을 같이 호출.
    avformat_network_init();

    // 사용자가 avformat_alloc_context() 함수를 이용하여 직접 생성한 후 넘겨줘도 되고, NULL을 가리키는 포인트 변수를 넘겨서 내부에서 생성하도록 하셔도 됩니다.
    // 참고로 AVFormatContext 구조체는 FFmpeg Library중 avformat Library의 가장 핵심적인 데이터 타입으로,
    // 주로 I / O 및 Muxing / Demuxing 과정에 사용됩니다.
    // 마치 c library의 FILE 포인터와 같이 미디어 I / O 및 Muxing / Demuxing에 필요한 정보들을 포함하고 있습니다.
    pFormatCtx = avformat_alloc_context();


*/
/*------------ 미디어 파일 열기 단계 ------------*//*



    // Open video file
    // avformat_open_input() 함수는 첫번째 인자로 넘긴 AVFormatContext 구조체에 I/O 및 Muxing/Demuxing에 필요한 정보를 채워주는 역할을 합니다.
    // 세번째 패러미터는 강제로 Input Format을 지정할 경우에 사용됩니다. 그냥 NULL 값으로 지정하시면 입력 소스에 따라서 자동으로 Input Format을 검색합니다.
    // 마지막 패러미터는 demuxer의 추가 옵션을 지정할 때 사용합니다. 이 패러미터 역시 잘 사용하지 않으므로 그냥 NULL 값을 넣어주시면 됩니다.
    // ( function proto: avformat_open_input (AVFormatContext **ps, const char *filename, AVInputFormat *fmt, AVDictionary **options) )
    if (avformat_open_input(&pFormatCtx, uri, NULL, NULL) != 0) {
        printf("Couldn't open source url : %s\n", uri);
        return -1; // Couldn't open file
    } else {
        printf("set format success!! from source url\n");
    }


*/
/*------------ 미디어 파일 정보 가져오기 단계 ------------*//*



    // avformat_open_input() 함수에서 미디어 파일을 열 때, 파일 헤더 정보가 존재하면 미리 같이 읽습니다.
    // Input Format에 따라서는 파일 헤더 정보에 모든 내용이 기록된 포맷도 있겠지만 정보가 충분하지 않거나, 헤더가 없는 Format도 존재합니다.
    // 이 경우 부족한 정보를 얻기 위해서는 어떻게 해야할까요? 그렇습니다. 충분한 정보를 얻기 위해서 미리 Data를 조금 읽어들여서
    // Parsing 또는 Decode 해보는 방법이 있습니다. FFmpeg Library는 이를 위해서 avformat_find_stream_info() 함수를 제공합니다.

    // 두번째 패러미터는 Codec 옵션을 지정할 때 사용합니다. 때에 따라서는 정보를 얻기 위해서 미리 Data를 Decode 해봐야 할 때가 있는데, 그 때 임시로 생성할 Codec에 넘겨줄 Codec 옵션을 지정합니다.
    // 역시 잘 사용하지 않으므로 그냥 NULL 값을 넣어주시면 됩니다.

    // 참고로 avformat_find_stream_info() 는 blocking 함수 입니다.
    // Input Source로 Network Protocol을 사용한다면 정보가 담겨있는 패킷이 발견될 때까지 계속해서 Read를 시도하기 때문에
    // 시간이 지연되거나, 최악의 경우 패킷이 들어오지 않는다면, block되어 버리는 일이 발생할 수도 있으니 주의합시다.

    // Retrieve stream information (Retrieve: 되찾아오다, 검색하다)
    // ( function proto: avformat_find_stream_info( AVFormatContext *ic, AVDictionary ** options ) )
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("Couldn't find stream information.\n");
        return -1;
    } else {
        printf("get stream information from format..\n");
    }


    // FFmpeg Library에서 처리하는 Stream의 Type은 6가지 enum AVMediaType { ... } 에 저장되어 있다.
    // Find the first video stream
    int videoStream = -1, i;
    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO
            && videoStream < 0) {
            videoStream = i;
        }
    }
    if (videoStream == -1) {
        printf("Didn't find a video stream from source url");
        return -1; // Didn't find a video stream
    } else {
        printf("video stream index : %d\n", i);
    }
}

*/
#include <stdio.h>
#include <stdint.h>
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

}
#include <string.h>
#include <iostream>
#include <opencv/cxmisc.h>

cv::Mutex imgmtx;
int imgBufSize;
bool isFull1=false;
bool finishFlag1 = true;
int wid,hei,cha;
uint8_t * dst;

int videoWidth = 0;
int videoHeight = 0;

const char *uri = "rtsp://admin:1234@192.168.0.200:554/video1";
AVFormatContext *pFormatCtx = NULL;
AVCodecContext *pCodecCtx = NULL;
AVCodec *pCodec = NULL;
AVFrame * pFrame = NULL;
int videoStream = -1;

int init_rtsp() {

    int numBytes = 0, i;

    // it must set to setDataSource for play.
    // avformat_open_input 메서드가 filename을 const char 의 pointer type으로 parameter를 받으므로 다음의 과정이 필요.

    if (uri == NULL) {
        printf("Please set the DataSource: ffmpeg_test\n");
        return -1;
    } else {
        printf("rtsp set source url>> %s\n", uri);
    }



/*------------ 라이브러리 초기화 단계 ------------*/


    // ffmpeg에서 지원되는 모든 Demuxer, Muxer, Protocol 및 Codec 등을 사용할 수 있도록 등록.
    // get muxer, demuxer and protocol definitions.
    // Initialize libavformat and register all the muxers, demuxers and protocols. - in FFmpeg Guide
    av_register_all();

    // network 사용을 위한 추가 초기화 작업을 수행.
    // 종료 시 해제 함수 avformat_network_deinit(); 을 같이 호출.
    avformat_network_init();

    // 사용자가 avformat_alloc_context() 함수를 이용하여 직접 생성한 후 넘겨줘도 되고, NULL을 가리키는 포인트 변수를 넘겨서 내부에서 생성하도록 하셔도 됩니다.
    // 참고로 AVFormatContext 구조체는 FFmpeg Library중 avformat Library의 가장 핵심적인 데이터 타입으로,
    // 주로 I / O 및 Muxing / Demuxing 과정에 사용됩니다.
    // 마치 c library의 FILE 포인터와 같이 미디어 I / O 및 Muxing / Demuxing에 필요한 정보들을 포함하고 있습니다.
    pFormatCtx = avformat_alloc_context();


/*------------ 미디어 파일 열기 단계 ------------*/


    // Open video file
    // avformat_open_input() 함수는 첫번째 인자로 넘긴 AVFormatContext 구조체에 I/O 및 Muxing/Demuxing에 필요한 정보를 채워주는 역할을 합니다.
    // 세번째 패러미터는 강제로 Input Format을 지정할 경우에 사용됩니다. 그냥 NULL 값으로 지정하시면 입력 소스에 따라서 자동으로 Input Format을 검색합니다.
    // 마지막 패러미터는 demuxer의 추가 옵션을 지정할 때 사용합니다. 이 패러미터 역시 잘 사용하지 않으므로 그냥 NULL 값을 넣어주시면 됩니다.
    // ( function proto: avformat_open_input (AVFormatContext **ps, const char *filename, AVInputFormat *fmt, AVDictionary **options) )
    if (avformat_open_input(&pFormatCtx, uri, NULL, NULL) != 0) {
        printf("Couldn't open source url : %s\n", uri);
        return -1; // Couldn't open file
    } else {
        printf("set format success!! from source url\n");
    }


/*------------ 미디어 파일 정보 가져오기 단계 ------------*/


    // avformat_open_input() 함수에서 미디어 파일을 열 때, 파일 헤더 정보가 존재하면 미리 같이 읽습니다.
    // Input Format에 따라서는 파일 헤더 정보에 모든 내용이 기록된 포맷도 있겠지만 정보가 충분하지 않거나, 헤더가 없는 Format도 존재합니다.
    // 이 경우 부족한 정보를 얻기 위해서는 어떻게 해야할까요? 그렇습니다. 충분한 정보를 얻기 위해서 미리 Data를 조금 읽어들여서
    // Parsing 또는 Decode 해보는 방법이 있습니다. FFmpeg Library는 이를 위해서 avformat_find_stream_info() 함수를 제공합니다.

    // 두번째 패러미터는 Codec 옵션을 지정할 때 사용합니다. 때에 따라서는 정보를 얻기 위해서 미리 Data를 Decode 해봐야 할 때가 있는데, 그 때 임시로 생성할 Codec에 넘겨줄 Codec 옵션을 지정합니다.
    // 역시 잘 사용하지 않으므로 그냥 NULL 값을 넣어주시면 됩니다.

    // 참고로 avformat_find_stream_info() 는 blocking 함수 입니다.
    // Input Source로 Network Protocol을 사용한다면 정보가 담겨있는 패킷이 발견될 때까지 계속해서 Read를 시도하기 때문에
    // 시간이 지연되거나, 최악의 경우 패킷이 들어오지 않는다면, block되어 버리는 일이 발생할 수도 있으니 주의합시다.

    // Retrieve stream information (Retrieve: 되찾아오다, 검색하다)
    // ( function proto: avformat_find_stream_info( AVFormatContext *ic, AVDictionary ** options ) )
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("Couldn't find stream information.\n");
        return -1;
    } else {
        printf("get stream information from format..\n");
    }


    // FFmpeg Library에서 처리하는 Stream의 Type은 6가지 enum AVMediaType { ... } 에 저장되어 있다.
    // Find the first video stream

    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO
            && videoStream < 0) {
            videoStream = i;
        }
    }
    if (videoStream == -1) {
        printf("Didn't find a video stream from source url");
        return -1; // Didn't find a video stream
    } else {
        printf("video stream index : %d\n", i);
    }

    /*------------ 디코더 준비 단계 ------------*/


    // Decoding의 경우에는 앞서 avformat_open_input() 함수와 avformat_find_stream_info() 함수를 거치면서
    // AVFormatContext 구조체 내의 AVStream 구조체 내에 codec 이라는 변수명으로 자동으로 생성 되어 있으며,
    // 사용자는 여기에 추가적으로 Decoder에 대한 정보만 붙여주면 됩니다.

    // Get a pointer to the codec context for the video stream
    pCodecCtx = pFormatCtx->streams[videoStream]->codec;

    // avcodec_find_decoder() 함수에 codec_id 값을 넘겨줌으로서 FFmpeg Library에 해당 Codec용 Decoder정보가 있는지 찾아볼 수 있습니다.
    // 일반적으로 FFmpeg Library 자체 S/W Decoder가 먼저 검색되어지며, 만약 하나의 Codec에 대해서 복수개의 Decoder가 존재하며,
    // 다른 Decoder를 사용하고 싶다거나 할 경우에는 avcodec_find_decoder_by_name() 함수를 통해서 이름으로 Decoder를 검색할 수도 있습니다.
    // 하지만 보통은 FFmpeg Library를 빌드 할 때 옵션을 통해서 코덱당 하나의 Decoder만 나오도록 조절 합니다. 만약, 해당 코덱용 Decoder가 없는 경우에는 NULL 값을 리턴합니다.

    // Find the decoder for the video stream
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    if(pCodec==NULL) {
        printf("Codec not found.\n");
        return -1; // Codec not found
    }

    // 만일 Decoder 정보가 존재한다면, AVCodecContext에 해당 정보를 넘겨줘서 Decoder로서 초기화 하는 일이 남았습니다. 이 때 사용하는 함수가 avcodec_open2() 입니다.
    // 첫번째 인자는 AVCodecContext 구조체 입니다.
    // 두번째 인자는 방금 찾은 AVCodec 구조체 입니다.
    // 마지막 인자는 Decoder 초기화에 필요한 추가 옵션입니다.
    // 가령, 비디오의 경우 bitrate정보 등을 넣어 줄 수도 있고, decoding 시 thread 사용 여부 등을 결정해 줄 수도 있습니다. 일반적으로 NULL 값을 사용합니다.

    if(avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        printf("Could not open codec.\n");
        return -1; // Could not open codec
    }

    // get codec size
    videoWidth = pCodecCtx->width;
    videoHeight = pCodecCtx->height;

    printf("videoWidth >> %d, videoHeight >> %d\n", videoWidth, videoHeight);


    // 위에서 av_read_frame() 설명할 때, AVPacket 구조체가 파일로부터 인코딩 된 비디오 / 오디오 데이터를 읽어 저장하기 위한 구조체라고 했었습니다.
    // 그렇다면 반대로 디코딩 된 결과 데이터를 저장하는 구조체도 있지 않을까요? 그렇습니다. 바로 그 역할을 하는 것이 AVFrame 구조체 입니다

    // Allocate video frame
    pFrame = av_frame_alloc();

    if(pFrame == NULL) {
        printf("Could not allocate video frame.\n");
        return -1;
    }

}

void decoding() {
    int frameFinished;

    // AVPacket 구조체는 FFmpeg Library에서 인코딩된 비디오 데이터를 저장하기 위한 구조체 입니다.
    // Decoder에 이 구조체의 데이터가 전달되서 Decoding 과정을 수행합니다.
    AVPacket packet;

    while(av_read_frame(pFormatCtx, &packet)>=0 && finishFlag1) {
        std::cout<<"get"<<std::endl;
        int returnval = 0;
        // Is this a packet from the video stream?
        if(packet.stream_index==videoStream) {

            avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);

            if (frameFinished) {
                // calculate stride.
                isFull1=true;
                imgmtx.lock();
                wid = pFrame->width;
                hei = pFrame->height;
                cha = pFrame->channels;
                int dstStride = pFrame->linesize[0];
                int srcStride = pFrame->linesize[0];
                imgBufSize=sizeof(uint8_t)*videoHeight*dstStride;
                dst = (uint8_t*)malloc(imgBufSize);
                uint8_t * src = (uint8_t*) (pFrame->data[0]);

                // Depending on the stride and gait window frame, thus requiring a progressive copy

                for (int h = 0; h < videoHeight; h++) {
                    memcpy(dst + h * dstStride, src + h * srcStride, srcStride);
                }

                free(dst);
                imgmtx.unlock();
            }

        }
        av_free_packet(&packet);
        //av_packet_unref(&packet);
    }
}

void destroy() {
    avformat_network_deinit();
    //av_free(buffer);
    //av_free(pFrameRGBA);

    // Free the YUV frame
    av_free(pFrame);

    // Close the codecs
    avcodec_close(pCodecCtx);



    /*------------ 미디어 파일 닫기 단계 ------------*/

    // avformat_close_input() 함수는 단순히 열려있는 파일을 닫는 기능 뿐만아니라
    // avformat_open_input() 또는 avformat_alloc_context() 함수를 통해 할당된 AVFormatContext 객체 s 를 해제까지 해줍니다.
    // 즉, 따로 free 계열의 함수를 호출할 필요 없이, 이 함수 하나로 파일 닫기 및 자원 해제가 가능합니다.

    // Close the video file
    avformat_close_input(&pFormatCtx);    // ( function proto: avformat_close_input (AVFormatContext **s) )
}

/*
int main() {
    init_rtsp();
    decoding();
    destroy();
    return 0;
}
*/


