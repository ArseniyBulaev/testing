# Команда (Command)
1. Создать объект, представляющий собой вызов операци
2. Сохранить в нём все необходимые параметры операции
3. Когда операция готова к выполнению, использовать для этого универсальный интерфейс (метод run())

# Объект значение (Value Object)
Проектируем класс так, чтобы его экземпляры представляли собой неизменяемые значения.
В результате любых операций с данным объектом должен получаться новый объект.
!!! Все объекты-значения должны реализовывать операцию сравнения !!!