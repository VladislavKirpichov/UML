# Описание
Сервер принимает get запросы и может отдавать JSON.
Если зайти на localhost:8080/user/?... и вместо ... написать
переменные, то сервер вернет json с этими переменными.
Также есть класс Logger для логирования ошибок и сообщений (пока только в консоль).
### Новые фичи которые добавлю в ближайшее время:

- добавить тесты
- обработка http соединения и отправка 404 или bad request
- классы handler-ов