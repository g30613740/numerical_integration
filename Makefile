# Компилятор и флаги
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -O2
LDFLAGS  = -lm

# Имя исполняемого файла
TARGET = num_integ

# Директории
SRCDIR   = src
BUILDDIR = build

# Автоматически находим все .cpp в src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Цель по умолчанию
all: $(TARGET)

# Линковка
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Компиляция
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки build
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean run