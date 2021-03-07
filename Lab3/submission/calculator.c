#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)
#define finit_module(fd, param_values, flags) syscall(__NR_finit_module, fd, paramvalues, flags)
#define delete_module(name, flags) syscall(__NR_delete_module, name, flags)

long addition (char* AllParams);
long substraction (char* AllParams);
long multiplication (char* AllParams);
void LoadModule(char* AllParams);
void UnLoadModule();
long ReadResult();


const char *moduleName = "calculatorModule.ko";
const char *moduleNameNoExtension = "calculatorModule";
char paramsNew[256];

int main() {

    char operator;
    char *operation;


    int input1=0;
    int input2=0;
    long result = 0;

    while(1)
    {
        input1=0;
        input2=0;
        result = 0;


        printf("=======================\n");
        printf("Enter operation [sum - sub - mul - exit]: ");
        scanf("%s",operation);

        if(strcmp(operation,"exit")==0){
            break;
        }

        printf("Enter two operands (space separated): ");
        scanf("%d %d", &input1, &input2);

        //Concate operation, input1, input2 to a string
        sprintf(paramsNew, "operationParam=%s firstParam=%d secondParam=%d", operation, input1, input2);


        if(strcmp(operation,"sum")==0){
            result = addition (paramsNew);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"sub")==0){
            result = substraction (paramsNew);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"mul")==0){
            result = multiplication (paramsNew);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else{
            printf("Invalid option\n");
        }
    }

    return 0;
}

long addition (char* AllParams)
{
    long result = 0;
    LoadModule(AllParams);
    result = ReadResult();
    UnLoadModule();

    return result;
}

long substraction (char* AllParams)
{
    long result = 0;
    LoadModule(AllParams);
    result = ReadResult();
    UnLoadModule();

    return result;
}

long multiplication (char* AllParams)
{
    long result = 0;
    LoadModule(AllParams);
    result = ReadResult();   
    UnLoadModule();

    return result;
}

void LoadModule(char* Params) {
    int fd, use_finit;
    size_t image_size;
    struct stat st;
    void *image;

    fd = open(moduleName, O_RDONLY);
    fstat(fd, &st);
    image_size = st.st_size;
    image = malloc(image_size);
    read(fd, image, image_size);
    if(init_module(image, image_size, Params) != 0) {
        perror("init_module");
    }
}

void UnLoadModule() {
    if(delete_module(moduleNameNoExtension, O_NONBLOCK)!=0) {
        perror("delete_module");
    }
}

long ReadResult() {
    long result=0;
    FILE *file = fopen("/sys/module/calculatorModule/parameters/resultParam", "r");
    if(file) {
        fscanf(file, "%ld", &result);
    }
    return result;
}