# Compilador C++
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte
SRCS = main.cpp Fila.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Nome do executável
TARGET = programa_fila

# Regra padrão
all: $(TARGET)

# Regra para linkar os objetos e criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos fonte em objetos
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)