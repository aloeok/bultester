# bultester
Простая тестирующая система для проверки решений задач по программированию, реализованных на языке C стандарта C89.

**Номера задач, для которых готовы тесты:**

	0017		0018		0023-001	0023-002
	
	0023-003	0050		0065		0066

	0067-001	0067-002	0067-003	0067-004

	0067-005	0068-001	0068-002	0068-003
	
	0069		0090


# 1. Как использовать
- Скачайте все папки и файлы из папки `src` (`https://github.com/aloeok/bultester/tree/main/src`)
- Поместите их на своём устройстве в ту же папку, где лежат *файлы с исходным кодом* ваших решений
- После этого у вас должна быть папка, в которой лежат:
	- файлы с *исходным кодом ваших решений* (..., `0050.c`, `0067-001.c`, ...)
	- файл `ans_checker.exe` (нужен только если вы работаете в **Windows**)
	- файл `ans_checker.c` (нужен только если вы работаете в **Linux**)
	- файл `prog_list.btdata`
	- файл `tester.sh`
	- файл `tests_data_merger.sh`
	- папка `test_data` (с её содержимым)
- Для работы тестировщика также необходимы:
	- установленный *компилятор gcc*
	- любой *интерпритатор shell-команд* (проверенный вариант для **Windows** - *GitBash*, для **Linux** - *стандартная командная оболочка Unix*)
- В папке `test_data` лежат файлы, в которых содержатся данные для тестирования решений.
    - В одном файле - набор тестов для проверки решения одной задачи.
    - Сюда можно добавлять свои тесты *(подробнее о том, как это делать - см. [пункт 4](https://github.com/aloeok/bultester#4-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D0%B5-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-test_data))*.
- В файле `prog_list.btdata` содержится список номеров задач для тестирования.
    - После запуска тестировщик протестирует ваши решения для задач, номера которых указаны в этом файле.
    - Содержимое файла можно изменить, как вам нужно, открыв его в любом текстовом редакторе *(подробнее - см. [пункт 3](https://github.com/aloeok/bultester#3-%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87-%D0%B4%D0%BB%D1%8F-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-prog_listbtdata))*.
    - **Указывать в файле номер задачи для тестирования её решения можно вне зависимости от того, есть для него тестовые данные или нет.** (Если в папке `test_data` для решения задачи с указанным номером нет данных для его тестирования, тестировщик сообщит вам об этом. Если в `test_data` есть тесты для решения задачи, его номер необязательно указывать в файле `prog_list.btdata`)
- **Остальные файлы менять не нужно**
- Чтобы начать тестирование, запустите файл `tester.sh`
	- Для **Windows**:
		- Убедитесь, что в папке со всеми нужными файлами лежит `ans_checker.exe`
		- Запустите файл `tester.sh` (например, с помощью *GitBash*)
	- Для **Linux**:
		- Убедитесь, что в папке со всеми нужными файлами лежит `ans_checker.с`
		- Откройте командную оболочку Linux и перейдите в директорию со всеми файлами:
		
			`cd <path_to_folder_with_source_files>`
		- Выполните следующие команды:
		
			`chmod +x tester.sh`
		
			`chmod +x tests_data_merger.sh`
		
			`gcc -o ans_checker ans_checker.c`
		
			`./tester.sh`
	- *Подробнее про тестирование - см. [пункт 2](https://github.com/aloeok/bultester#2-%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D0%B9)*

# 2. Тестирование решений
- Каждый тест для каждого решения состоит из **входных данных** и правильного результата работы программы при этих входных данных (**ожидаемых выходных данных** и **ожидаемого кода завершения программы** (значение, возвращаемое функцией *main*)).
- При выполнении очередного теста, тестировщик компилирует и запускает вашу программу с решением, передаёт ей **входные данные**, получает *результат работы* (в виде **выходных данных** и **кода завершения программы**), сравнивает его с *правильным результатом работы* и сообщает вам результат тестирования.
- __Тестировщик также проверяет выполнение требований задания:__
	- Вывод значений - по одному на строку
	- Отсутствие лишнего вывода **(в том числе лишних пробелов)**
	- Правильная компиляция с заданными ключами (`gcc -c -std=c89 -Wall -Werror -pedantic -lm`)
	- Обработка некорректного ввода (программа ничего не выводит и возвращает значение 1)
- Для всех решений максимальное время тестирования составляет **5 секунд**, после чего тестирование прерывается
- После каждого непройденного теста выводятся тестовые входные данные, результат работы вашей программы и ожидаемый результат работы. **Удостоверьтесь, что это действительно ваша программа неправильная, а не тестовые данные или тестировщик**.
- В случае любой ошибки (начиная от несуществующего файла или ошибки компиляции и заканчивая неправильным ответом) тестировщик прерывает текущий тест, выводит сообщение об ошибке и переходит к следующему тесту.

# 3. Список задач для тестирования (`prog_list.btdata`)


# 4. Данные для тестирования (`test_data`)
