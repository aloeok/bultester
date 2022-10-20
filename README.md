# bultester
Простая тестирующая система для проверки решений задач по программированию, реализованных на языке C стандарта C89.

**Номера задач, для которых готовы тесты:**

	0271		0272		0273		0274



# 1. Как использовать
- Скачайте всё содержимое папки `src` (`https://github.com/aloeok/bultester/tree/main/src`) в ту же папку на вашем компьютере, где лежат файлы с **исходным кодом** ваших решений
- После этого у вас должна быть *папка тестировщика*, в которой лежат **только**:
	- файлы с исходным кодом ваших решений (..., `0050.c`, `0067-001.c`, ...)
	- файл `ans_checker.c`
	- файл `tester.sh`
	- файл `tests_data_merger.sh`
	- файл `prog_list.btdata`
	- папка `test_data` (с её содержимым)
- **для Linux:** откройте командную оболочку, переместитесь в *папку тестировщика* (`cd "path_to_folder"`) и выполните следующие команды: `chmod +x tester.sh` , `chmod +x tests_data_merger.sh` .
- Для работы тестировщика также необходимы:
	- установленный компилятор **gcc**
	- **для Windows:** любой интерпритатор shell-команд (проверенный вариант - **Git Bash**)
- В папке `test_data` лежат файлы, в которых содержатся **данные для тестирования решений**.
    - В одном файле - набор тестов для проверки решения одной задачи.
    - Сюда можно добавлять свои тесты *(подробнее о том, как это делать - см. [пункт 4](https://github.com/aloeok/bultester#4-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D0%B5-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-test_data))*.
- В файле `prog_list.btdata` содержится **список номеров задач для тестирования**.
    - После запуска тестировщик протестирует ваши решения для задач, номера которых указаны в этом файле.
    - Содержимое файла можно изменить, как вам нужно, в зависимости от того, какие задачи вам нужно протестировать. Для этого достаточно открыть файл в любом текстовом редакторе *(подробнее - см. [пункт 3](https://github.com/aloeok/bultester#3-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-prog_listbtdata))*.
    - *В файле необязательно указывать номера всех задач, для решений которых есть тесты*. Можно указать номера только тех задач, которые вам нужно протестировать.
- *Остальные файлы менять не нужно!*
- **ЗАПУСК ТЕСТИРОВАНИЯ**
	- **Windows**:
		- Откройте интерпритатор shell-команд (например, Git Bash), переместитесь в *папку тестировщика* (`cd "path_to_folder"`), и выполните команду:
			- `./tester.sh`
			- или `./tester.sh > "file_name"` (сохранит результаты всех тестов в указанный файл `file_name`)
	- **Linux**:
		- **Убедитесь, что вы выполнили 3 пункт**
		- Откройте командную оболочку, переместитесь в *папку тестировщика* (`cd "path_to_folder"`), и выполните команду:
			- `./tester.sh`
			- или `./tester.sh > "file_name"` (сохранит результаты всех тестов в указанный файл `file_name`)

**ВАЖНО :**

После каждого непройденного теста выводятся тестовые входные данные, результат работы вашей программы и ожидаемый результат работы.

**Удостоверьтесь, что это действительно ваша программа неправильная, а не тестовые данные или тестировщик. Причиной непройденного теста может быть в том числе разное понимание условия задачи у вас и автора теста или, хоть и маловероятно, ошибка в тестовых данных или тестирующей программе.**

*Подробнее про тестирование - см. [пункт 2](https://github.com/aloeok/bultester#2-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D0%B9)*

# 2. Тестирование решений
- Каждый тест для каждого решения состоит из **входных данных** и правильного результата работы программы при этих входных данных - **ожидаемых выходных данных** и **ожидаемого кода завершения программы** (значение, возвращаемое функцией `main`).
- При выполнении очередного теста, тестировщик компилирует и запускает вашу программу с решением, передаёт ей **входные данные**, получает **выходные данные** и **код завершения**, сравнивает их с **ожидаемыми выходными данными** и **ожидаемым кодом завершения** и сообщает вам результат тестирования.
- **Тестировщик также проверяет выполнение следующих требований:**
	- Вывод значений - **по одному на строку**
	- Отсутствие лишнего вывода **(в том числе лишних пробелов)**
	- **Правильная компиляция с заданными ключами (**`gcc -c -std=c89 -Wall -Werror -pedantic -lm`**)**
	- Обработка некорректного ввода **(программа ничего не выводит и возвращает значение** `1`**)**
	- Для любого решения **время работы составляет не более 5 секунд**
	- Значения типа `double` сравниваются с точностью до **5 знака после запятой**
- После каждого непройденного теста выводятся тестовые входные данные, результат работы вашей программы и ожидаемый результат работы. **Удостоверьтесь, что это действительно ваша программа неправильная, а не тестовые данные или тестировщик**.
- В случае любой ошибки (начиная от несуществующего файла или ошибки компиляции и заканчивая неправильным ответом) тестировщик прерывает текущий тест, выводит сообщение об ошибке и переходит к следующему тесту.

# 3. Список задач для тестирования (`prog_list.btdata`)
- В данном файле содержится список номеров задач, решения которых будут протестированы при запуске тестирования.
- Для корректной работы тестировщика должны быть соблюдены следующие условия:
	- Номера задач и названия соответствующих исходных файлов решения соответствуют требованиям задания (например: название - `0067-001`, файл с исходным кодом решения - `0067-001.c`)
	- В файле `prog_list.btdata`:
		- ничего не содержится, кроме номеров задач
		- каждый номер - на отдельной строке
		- на **каждой** строке, кроме последней - номер одной задачи и **больше ничего, в том числе пробелов в конце строки**
		- **последняя строка - пустая!**
		- **каждый номер задачи записан в файле не более 1 раза!**

# 4. Данные для тестирования (`test_data`)
- Как нибудь потом тут появится описание, а пока будем считать, что интуитивно понятно, как их делать :)
