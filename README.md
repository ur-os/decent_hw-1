## Домашнее задание №1

#### Сборка с помощью cmake:
```console
$ git clone git@github.com:ur-os/decent_hw-1.git
$ cd hw-1 && mkdir build && cd build
$ cmake ./
$ make
```
#### Использование:
```console
$ ./hw-1 --file <filename> --numbilets [0-9] --parameter [0-9]
```
  - file - путь до файла со списком ФИО студентов (по одному ФИО на строку)
  - numbilets целое число билетов
  - parameter целое число, меняющее распределение билетов

#### Характеристики:
  - равномерность распределения ограничивается стандартной rand()
  - детерминированность обеспечивается константным сидом
  - при полном совпадении ФИО, происходят коллизии
  
#### Краткое описание:
  Cид для генерации - это ФИО с параметром.
  Передаём их в sha256, получаем хэш, ксорим его части
  с самим собой, выдаём по модулю numbilets.
  
### Результат по набору с `parameter = 2`:
![alt text](https://sun9-17.userapi.com/f7vZ5NBfaOtJYBiWQ0NKmo1tVjnXa0jYye9WXA/Vof7e7JW98A.jpg)
 
 
### Результат по набору с `parameter = 43`:
![alt text](https://sun9-51.userapi.com/9pIPSh6oZtnkJyDIKYs9qtmbqU9WJ3UKbW5p5g/75fuYMtMsKc.jpg)
