# bultester
Простая тестирующая система для проверки решений задач по программированию, реализованных на языке C стандарта C89.

# 1. Как использовать
- Скачайте все папки и файлы из папки `src` (`https://github.com/aloeok/bultester/tree/main/src`)
- Поместите их на своём устройстве в ту же папку, где лежат *файлы с исходным кодом* ваших решений
- После этого у вас должна быть папка, в которой лежат:
	- файлы с *исходным кодом ваших решений* (..., `0050.c`, `0067-001.c`, ...)
	- файл `ans_checker.exe` (и его исходник `ans_checker.c`, который в принципе не нужен)
	- файл `prog_list.btdata`
	- файл `tester.sh`
	- файл `tests_data_merger.sh`
	- папка `test_data` (с её содержимым)
- Для работы тестировщика также необходимы:
	- установленный *компилятор gcc*
	- любой *интерпритатор shell-команд* (как вариант - *git bash* или *командная оболочка Unix*)
- В папке `test_data` лежат файлы, в которых содержатся данные для тестирования решений.
    - В одном файле - набор тестов для проверки решения одной задачи.
    - Сюда можно добавлять свои тесты *(подробнее о том, как это делать - см. [пункт 4](https://github.com/aloeok/bultester#3-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-prog_listbtdata))*.
- В файле `prog_list.btdata` содержится список номеров задач для тестирования.
    - После запуска тестировщик протестирует ваши решения для задач, номера которых указаны в этом файле.
    - Содержимое файла можно изменить, как вам нужно, открыв его в любом текстовом редакторе *(подробнее - см. [пункт 3](https://github.com/aloeok/bultester#3-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-prog_listbtdata))*.
    - **Указывать в файле номер задачи для тестирования её решения можно независимо от того, есть для него тестовые данные или нет.** (Если в папке `test_data` для решения задачи с указанным номером нет данных для его тестирования, тестировщик сообщит вам об этом. Если в `test_data` есть тесты для решения задачи, его номер необязательно указывать в файле `prog_list.btdata`)
- **Остальные файлы менять не нужно**
- Чтобы начать тестирование, запустите файл `tester.sh` (откройте с помощью интерпритатора shell-команд, или `./tester.sh` в командной оболочке). *Подробнее - см. [пункт 2](https://github.com/aloeok/bultester#3-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-prog_listbtdata)*

# 2. Тестирование решений


# 3. Список задач для тестирования (`prog_list.btdata`)


# 4. Данные для тестирования (`test_data`)
