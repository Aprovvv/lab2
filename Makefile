CC=gcc
FLAGS = -Wall
SOURCES=main.c add_noise.c dev_linear.c dev_exp.c experiment.c linear_equation.c model.c nonlinear_equation.c precision_analysis.c
OBJECTS=$(addprefix object_files/,$(notdir $(SOURCES:.c=.o)))
EXECUTABLE=start

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -lm -o $@

object_files/%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf object_files/*.o
