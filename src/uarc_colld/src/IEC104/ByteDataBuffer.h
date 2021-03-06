/*
 * ByteDataBuffer.h
 *
 *  Created on: 2014-10-14
 *      Author: root
 */

#ifndef BYTEDATABUFFER_H_
#define BYTEDATABUFFER_H_

#include <stdint.h>

namespace Uarc {
namespace Protocol {

/*****************************************************************************
 *  ByteDataBuffer 操作二进制数据工具
 *
 *  主要用于拼接报文
 *
 *
 * ***************************************************************************/

class ByteDataBuffer {
public:
	/*****************************************************************************
	 *  静态分配缓存区大小
	 * @参数 char *buffer        缓冲区指针
	 * @参数 int bufferSize      缓存区大小
	 *
	 * **************************************************************************/

	ByteDataBuffer(char *buffer, int bufferSize);
	/*****************************************************************************
	 *  动态分配缓存区大小
	 * @参数 char *buffer        缓冲区指针
	 * @参数 int bufferSize      缓存区大小
	 *
	 * **************************************************************************/
	ByteDataBuffer(int bufferSize);
	virtual ~ByteDataBuffer();
	/*****************************************************************************
	 *  写入一个字节
	 * @uint8_t data           一个字节数据
	 *
	 * **************************************************************************/

	int writeInt8(uint8_t data);
	/*****************************************************************************
	 *  写入short字节
	 * @uint16_t data           一个字节数据
	 *
	 * **************************************************************************/

	int writeInt16(uint16_t data);
	/*****************************************************************************
	 *  写入四个字节整数
	 * @uint16_t data           一个字节数据
	 *
	 * **************************************************************************/

	int writeInt32(uint32_t data);
	/*****************************************************************************
	 *  读出一个字节整数
	 * @uint16_t data           一个字节数据
	 *
	 * **************************************************************************/

	uint8_t readInt8();
	/*****************************************************************************
	 *  读出两个字节整数
	 * @uint16_t data           一个字节数据
	 *
	 * **************************************************************************/

	uint16_t readInt16();
	/*****************************************************************************
	 *  读出四个字节整数
	 * @uint16_t data           四个字节数据
	 *
	 * **************************************************************************/

	uint32_t readInt32();
	/*****************************************************************************
	 *  移动位置
	 * @参数  int pos            四个字节数据
	 *
	 * **************************************************************************/

	int seek(int pos);
	/*****************************************************************************
	 *  读取BCD码数据
	 * 参数 format 格式，#或者是9表示数据，"."表示小数点位置，S表示有无符号
	 *
	 比如规约定义的格式6: S##.##
	 格式7              ###.#
	 *
	 * **************************************************************************/

	double readBCD(const char *format);
	/*****************************************************************************
	 *  写入BCD码数据
	 * 参数 format 格式，#或者是9表示数据，"."表示小数点位置，S表示有无符号
	 *
	 参数 double   d 要写入的数据
	 参数：format   格式 参照上面函数
	 *
	 * **************************************************************************/

	void writeBCD(double d,const char *format);
	/*****************************************************************************
	 *  写入BCD码数据
	 * 参数 format 格式，#或者是9表示数据，"."表示小数点位置，S表示有无符号,G表示10^4~10^-3科学计数法
	 *l
	 参数 double   d 要写入的数据
	 参数：format   格式 参照上面函数
	 *
	 * **************************************************************************/
	void writeBCDG(double d,const char *format);
	/*****************************************************************************
	 *  读取日期类型
	 * 参数 format 格式，
	 *
	 *  结果存入 struct tm *tm
	 *
	 * **************************************************************************/

	int readDate(struct tm *tm,const char *format);
	/*****************************************************************************
	 *  写入字节数据
	 * 参数 uint8_t *buf 数据缓冲区
	 * 参数 int bufsize 数据长度

	 *
	 * **************************************************************************/

	int writeBytes(uint8_t *buf, int bufsize);
	/*****************************************************************************
	 *  读出字节数据
	 * 参数 uint8_t *buf 数据缓冲区
	 * 参数 int bufsize 数据长度
	 *
	 * **************************************************************************/

	int readBytes(uint8_t *buf, int bufsize);
	/*****************************************************************************
	 *  读出字符串
	 *

	 *
	 * **************************************************************************/

	int readString(char *buf, int bufsize);
	/*****************************************************************************
	 *  写入字符串 ，长度不够填写'\0'
	 *
	 * 参数 char *buf 数据缓冲区
	 * 参数 int bufsize 数据长度

	 * **************************************************************************/

	int writeString(char *buf, int bufsize);
	/*****************************************************************************
	 *  写入日期类型
	 *
	 * struct tm *tm 日期数据
	 *  char *format 日期格式

	 * **************************************************************************/

	void writeDate(struct tm *tm,const char *format);
	/*****************************************************************************
	 * 读入日期类型格式1数据
	 *
	 * struct tm *tm 日期数据
	 * **************************************************************************/

	int readDateFrm1(struct tm *tm);
	/*****************************************************************************
	 * 写入日期类型格式1数据
	 *
	 * struct tm *tm 日期数据
	 * **************************************************************************/

	int writeDateFrm1(struct tm *tm);

	inline int getPos() {
		return pos;
	}
	inline uint8_t *getTail() {
		return tail;
	}
	inline uint8_t *getBufferStart() {
		return start;
	}
	inline int getSize() {
		if(size>pos)
		  return size;
		else
		 return pos;
	}
	inline bool isNull(){
		return nullSign;
	}
	inline int getLength(){
		return length;
	}
private:
	int isAlloc;
	int length;
	int initpos;
	int pos;
	int size;
	bool nullSign;
	uint8_t *tail;
	uint8_t *start;
};

}//namespace Protocol
}//namespace Uarc

#endif /* BYTEDATABUFFER_H_ */
