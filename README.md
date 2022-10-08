# bultester
Простая тестирующая система для проверки решений задач по программированию, реализованных на языке C стандарта C89.

**Номера задач, для которых готовы тесты:**

	0017		0018		0023-001	0023-002
	
	0023-003	0050		0065		0066

	0067-001	0067-002	0067-003	0067-004

	0067-005	0068-001	0068-002	0068-003
	
	0069		0090


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
- **Остальные файлы менять не нужно**
- **ЗАПУСК ТЕСТИРОВЩИКА**
	- **Windows**:
		- Запустите файл `tester.sh` (например, с помощью *GitBash* : двойной клик -> открыть с помощью... -> Git Bash)
		- Или запустите интерпритатор shell-команд (тот же Git Bash), переместитесь в *папку тестировщика* (`cd "path_to_folder"`), и выполните команду:
			- `./tester.sh`
			- или `./tester.sh > "file_name"` - сохранит результаты всех тестов в указанный файл `file_name`
	- **Linux**:
		- Запустите командную оболочку, переместитесь в *папку тестировщика* (`cd "path_to_folder"`), и выполните команду:
			- **Убедитесь, что вы выполнили 3 пункт**
			- `./tester.sh`
			- или `./tester.sh > "file_name"` - сохранит результаты всех тестов в указанный файл `file_name`
	- *Подробнее про тестирование - см. [пункт 2](https://github.com/aloeok/bultester#2-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D0%B9)*

# 2. Тестирование решений
- Каждый тест для каждого решения состоит из **входных данных** и правильного результата работы программы при этих входных данных - **ожидаемых выходных данных** и **ожидаемого кода завершения программы** (значение, возвращаемое функцией `main`).
- При выполнении очередного теста, тестировщик компилирует и запускает вашу программу с решением, передаёт ей **входные данные**, получает **выходные данные** и **код завершения**, сравнивает их с **ожидаемыми выходными данными** и **ожидаемым кодом завершения** и сообщает вам результат тестирования.
- **Тестировщик также проверяет выполнение следующих требований:**
	- **Вывод значений - по одному на строку**
	- **Отсутствие лишнего вывода (в том числе лишних пробелов)**
	- **Правильная компиляция с заданными ключами (`gcc -c -std=c89 -Wall -Werror -pedantic -lm`)**
	- **Обработка некорректного ввода (программа ничего не выводит и возвращает значение 1)**
	- **Для всех решений время работы составляет не более 5 секунд**
- После каждого непройденного теста выводятся тестовые входные данные, результат работы вашей программы и ожидаемый результат работы. **Удостоверьтесь, что это действительно ваша программа неправильная, а не тестовые данные или тестировщик**.
- В случае любой ошибки (начиная от несуществующего файла или ошибки компиляции и заканчивая неправильным ответом) тестировщик прерывает текущий тест, выводит сообщение об ошибке и переходит к следующему тесту.

# 3. Список задач для тестирования (`prog_list.btdata`)


# 4. Данные для тестирования (`test_data`)
