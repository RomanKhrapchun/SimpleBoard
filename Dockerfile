# Вибираємо базовий образ для Linux
FROM gcc:latest AS linux_builder
WORKDIR /app
COPY . /app
RUN g++ -o app_linux /Server/src/main/main.cpp

# Додаємо базовий образ для Windows через cross-compilation (MinGW)
FROM gcc:latest AS windows_builder
RUN apt-get update && apt-get install -y mingw-w64
WORKDIR /app
COPY . /app
RUN x86_64-w64-mingw32-g++ -o app_windows.exe main.cpp

# Створюємо фінальний образ, який містить лише результати збірки
FROM alpine:latest AS output
WORKDIR /output

# Копіюємо результати збірки з попередніх стадій
COPY --from=linux_builder /app/app_linux ./app_linux
COPY --from=windows_builder /app/app_windows.exe ./app_windows.exe
