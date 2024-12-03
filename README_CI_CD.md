## Как создать CI/CD в коде, который ранее был написан
**A. создайте папку (.github/workflows) в корневом репозитории**

![ci_cd1](https://github.com/user-attachments/assets/f4aa912d-f020-4af6-b9d5-901004593cf9)



**B. создайте ci-pipeline.yml внутри .github/workflows/**

![ci_cd1](https://github.com/user-attachments/assets/f450eb5d-04c8-473d-a84e-cc583884295d)



  1. Имя: CI Pipeline для запуска двух скриптов Bash

![ci_cd2](https://github.com/user-attachments/assets/a407d4f3-0bb0-4f3a-92ae-f7d15d01c31c)



  2. Триггеры: указывает, когда запускать рабочий процесс

![ci_cd3](https://github.com/user-attachments/assets/93bf2582-f385-4ba6-b10c-62a014cfac50)


  
  3. задания и запуски: определяет задачи для конвейера. Здесь есть только одно задание: запустить скрипт bash и компилировать скрипт bash и запустить программу c и это задание выполняется в Ubuntu (последняя версия)

![ci_cd4](https://github.com/user-attachments/assets/1514208f-b860-4cb7-8120-56af5c9680ef)


   3.1 Ниже приведены шаги, описывающие, что происходит во время запуска задания

  - Извлечь репозиторий

![ci_cd5](https://github.com/user-attachments/assets/8915b2b8-ce39-48e7-9171-3c827c339aad)


  - Устанавливает компилятор GCC (GNU Compiler Collection), который требуется для компиляции программ C/C++.

![ci_cd lats](https://github.com/user-attachments/assets/025214fc-573f-4589-bd3f-bee53bb9e999)

    
  - Сделайте скрипты Bash исполняемыми

![ci_cd6](https://github.com/user-attachments/assets/7192992c-e977-4de8-8725-cf61fc3cae0f)



  - Сохраните исполняемый файл как артефакт (после завершения рабочего процесса вы можете загрузить этот артефакт из пользовательского интерфейса действий GitHub для тестирования или распространения.)


![ci_cd8](https://github.com/user-attachments/assets/ac07fa7c-f0af-4163-b458-d483b247814b)


  - Запустите скрипт bash (автоматически при отправке кода или запросе на извлечение)

![ci_cd9](https://github.com/user-attachments/assets/ee777b04-8264-4d99-8299-c37d4ed9c876)

  - успех

![ci_cd10](https://github.com/user-attachments/assets/2eb0f0d3-3d40-4a12-a8e7-9e3f8927e73d)


