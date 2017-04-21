/**************************************************************************
*                                                                         *
* ImageStruct.h -- GDI 定义各种图片格式的结构                             *
*                                                                         *
**************************************************************************/





#ifndef _IMAGESTRUCT_
#define _IMAGESTRUCT_

typedef unsigned int	UINT;

/*******************************************************/
/* BMP位图文件包括4部分:                               */
/*    位图文件头结构BITMAPFILEHEADER                   */
/*	  位图信息头结构BITMAPINFOHEADER                   */
/*	  位图颜色表RGBQUAD                                */
/*    位图像素数据                                     */
/*******************************************************/
//14byte BMP文件头含有BMP文件的类型、大小、位图文件的保留字、位图数据距文件头的偏移量

//自定义的总是少2字节 故在View.h中引用系统自带的BMP结构 
//全局变量文件头 BITMAPFILEHEADER bfh;
//全局变量信息头 BITMAPINFOHEADER bih;         

typedef struct T_BITMAPFILEHEADER {
	WORD       bfType;           //2byte 位图文件的类型，必须为BM 0x424d       
	DWORD      bfSize;           //4byte 位图文件的大小，以字节为单位    
	WORD       bfReserved1;      //2byte 位图文件保留字，必须为0         
	WORD       bfReserved2;      //2byte 位图文件保留字，必须为0         
    DWORD      bfOffBits;        //4byte 位图数据距文件头的偏移量，以字节为单位
} BITMAPFILEHEADER_;

//定义成BITMAPFILEHEADER_ 不能定义成BITMAPFILEHEADER在MFC中已存在会重复定义

//40byte BMP位图信息头用于说明位图的尺寸等信息
typedef struct T_BITMAPINFOHEADER {
	DWORD      biSize;            //本结构所占用字节数
	LONG       biWidth;           //位图的宽度，以像素为单位
	LONG       biHeight;          //位图的高度，以像素为单位
	WORD       biPlanes;          //目标设备的级别，必须为1
	WORD       biBitCount;        //每个像素所需的位数，必须是1（双色）、
	                              //4（16色）、8（256色）或24（真彩色）之一
	DWORD      biCompression;     //位图压缩类型，必须是 0（不压缩）、
	                              //1（BI_RLE8压缩类型）或2（BI_RLE压缩类型）之一
	DWORD      biSizeImage;       //位图的大小，以字节为单位
	LONG       biXPelsPerMeter;   //位图水平分辨率，每米像素数
	LONG       biYPelsPerMeter;   //位图垂直分辨率，每米像素数
	DWORD      biClrUsed;         //位图实际使用的颜色表中的颜色数
	DWORD      biClrImportant;    //位图显示过程中重要的颜色数 
} BITMAPINFOHEADER_;

//BMP位图颜色表
typedef struct T_RGBQUAD
{
    BYTE       rgbBlue;		      //蓝色的亮度（值范围为0～255）
    BYTE       rgbGreen;		  //绿色的亮度（值范围为0～255）
    BYTE       rgbRed;			  //红色的亮度（值范围为0～255）
    BYTE       rgbReserved;	      //保留，必须为0
} RGBQUAD_;

//图片打开时存储信息的全局变量
	
#endif


