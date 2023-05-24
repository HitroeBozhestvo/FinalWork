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
	const char output[] = "Результат вычислений: %d\n";

	__asm {

		mov ecx, c
		cmp ecx, b // сравнение c и b
		jle f1 // если c <= b перейти к f1
		jg  second // если с > b перейти к second

		second :
		mov ecx, d
			cmp ecx, e // сравнение d и e
			je f1 // если d = e перейти к f1
			jne f2 // если d != e перейти к f2

			f1 :
		// Рассчёт функции
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


			// Вывод результата в консоль
			mov eax, ebx
			push eax //загрузка в стек результата вычислений
			lea ebx, print // загрузка адреса форматированной строки в ebx
			push ebx // загрузка содержимого ebx в стек
			call printf // вызов функции вывода
			add esp, 8 //очистка стека		
			jmp  end


			f2 :
		// Рассчёт функции
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

			// Вывод результата в консоль
			mov eax, ecx
			push eax // загрузка в стек результата вычислений 
			lea ebx, print // загрузка адреса форматированной строки в ebx
			push ebx // загрузка содержимого ebx в стек
			call printf // вызов функции вывода
			add esp, 8 //очистка стека
			jmp  end

			end :

	}
	system("pause");
	return 0;
}