# Описание
Сервер может обрабатывать websocket и http(пока нет) соединения. При подключении
websocket клиента работает как echo сервер, а при подключении по http
отдает простую html страницу\
Также есть класс Logger для логирования ошибок и сообщений (пока только в консоль)
### Новые фичи которые добавлю в ближайшее время:

- работа сервера в docker контейнере
- добавить тесты
- обработка http соединения и отправка 404 или bad request
- классы handler-ов
- добавить json serializer