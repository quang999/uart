#include<main.h>
#include<uart_mode1.h>


void uart_init(){
	//khoi tao uart mode 1 ,9600 baud
	SM0=0;SM1=1;// chon uart mode 1
	TMOD=0x20; // 0010 xxxx  - timer1 hoat dong che do nap lai
	TH1=0xFD; // toc do baud 9600
	TR1=1;//timer 1 bat dau chay
	TI=1; // san sang gui du lieu
	REN=1;//cho phep nhan du lieu
	}


char uart_data_ready(){
	return RI;
	}

char uart_read(){
	RI=0;
	return SBUF;
	}


void uart_write(char c){
	while(TI==0);
	TI=0;
	SBUF=c;
	}

void uart_write_text(char *str){
	unsigned char i=0;
	while(str[i]!=0){
		uart_write(str[i]);
		i++;
		}
	}


void main(){
	// char i;
	// char tinhyeu[]={'a',' ','y','e','u',' ','e'};
	uart_init();
  uart_write_text("xin chao 500 ae nhe");
	//for(i=0;i<7;i++){
	//	uart_write(tinhyeu[i]);}
	while(1){
		//if(uart_data_ready()==1){
		//	P2=uart_read();
		}
		}
		