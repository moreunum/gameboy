#ifndef MMU_H
#define MMU_H

void readByte(unsigned char addr);
void readWord(unsigned char addr);
void writeByte(unsigned char addr, int val);
void writeWord(unsigned char addr, int val);

#endif
