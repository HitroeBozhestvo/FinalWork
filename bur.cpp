#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <Windows.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int a, b, c, d, e, y;
	c = 10;
	d = 2;
	e = 5;
	a = 6;
	b = 3;
	const char output[] = "��������� ����������: %d\n";

	__asm {

		mov ecx, c
		cmp ecx, b // ��������� c � b
		jle f1 // ���� c <= b ������� � f1
		jg  second // ���� � > b ������� � second

		second :
		mov ecx, d
			cmp ecx, e // ��������� d � e
			je f1 // ���� d = e ������� � f1
			jne f2 // ���� d != e ������� � f2

			f1 :
		// ������� �������
		mov eax, c
			mov ebx, d
			mul ebx
			cdq
			mov ebx, e
			idiv ebx
			mov ebx, a
			mov ecx, b
			add ebx, ecx
			sub ebx, eax


			// ����� ���������� � �������
			mov eax, ebx
			push eax //�������� � ���� ���������� ����������
			lea ebx, print // �������� ������ ��������������� ������ � ebx
			push ebx // �������� ����������� ebx � ����
			call printf // ����� ������� ������
			add esp, 8 //������� �����		
			jmp  end


			f2 :
		// ������� �������
		mov eax, a
			mov ebx, b
			cdq
			idiv ebx
			mov ecx, eax
			mov y, ecx
			mov eax, d
			mov ebx, e
			mul ebx
			mov edx, c
			sub ecx, edx
			add ecx, eax

			// ����� ���������� � �������
			mov eax, ecx
			push eax // �������� � ���� ���������� ���������� 
			lea ebx, print // �������� ������ ��������������� ������ � ebx
			push ebx // �������� ����������� ebx � ����
			call printf // ����� ������� ������
			add esp, 8 //������� �����
			jmp  end

			end :

	}
	system("pause");
	return 0;
}