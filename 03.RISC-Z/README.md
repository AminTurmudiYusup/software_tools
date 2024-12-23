## Предварительное условие
1. Убедитесь, что CMake уже включен в CI/CD github (эти инструменты используются для автоматизации процесса компиляции и связывания вашего исходного кода в исполняемую программу)


![riscv7](https://github.com/user-attachments/assets/2de58100-cdd9-4320-b7e2-b9d19968223b)



2. Убедитесь, что симулятор включен в CI/CD github, я использую qemu (с поддержкой RISC-V)


![riscv6](https://github.com/user-attachments/assets/f8e3a8bc-94a5-4873-9e53-a77e88b6e3a4)



## Написание и тестирование программы
1. Написание программы для вычисления факториала для архитектуры RISC-V


![riscv2](https://github.com/user-attachments/assets/7326be99-3f3f-4cd9-8526-942e5a6b1019)




2. Написание программы для вычисления числа Фибоначчи для архитектуры RISC-V


![riscv3](https://github.com/user-attachments/assets/24755859-04fc-43c5-9a37-0600e59bbe25)


3. Написание модульного теста с использованием C


![riscv4](https://github.com/user-attachments/assets/62a99292-e6fd-421c-9d1f-05b85e85665a)

- Уже написанная программа будет вызвана и протестирована на C
- Поэтому я удалил системные вызовы для печати и остановки симулятора, поскольку они не нужны при вызове из C
4. Создайте файл CMakeLists для системы сборки, которая генерирует собственные скрипты сборки


![riscv1](https://github.com/user-attachments/assets/2426862d-47bb-4e0a-8489-17be099248b1)

  
5. Измените файл yaml для поддержки задачи CI/CD RISC-V



![riscv8](https://github.com/user-attachments/assets/a04fac90-846b-4201-8612-c850028a7819)


6. Запустите CI/CD



![riscv5](https://github.com/user-attachments/assets/d33a9d51-6469-4f84-8f33-b1c5af578219)
