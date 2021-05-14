#include "windows.h"
#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"
#include "locales.h"

const int BUFFER_SIZE = 128;
const int LNAME_LENGTH = 64;

char* getLayoutName(uint32_t code){
	int localesCount = sizeof(localeCodes) / sizeof(localeCodes[0]);
	for (int i = 0; i < localesCount; ++i)
		if (localeCodes[i].code == code)
			return localeCodes[i].name;
	return "Unknown";
}

int main(int argc, char* args[]){
	HKL handles[BUFFER_SIZE];
	char handleCodes[LNAME_LENGTH * BUFFER_SIZE];
	int count = GetKeyboardLayoutList(BUFFER_SIZE, handles);
	
	if (argc == 1){
		printf("%s\n", "Found keyboard layouts: ");
		for (int i = 0; i < count; ++i){
			uint32_t code = (uint64_t)handles[i] & 0xFFFF;
			char* name = getLayoutName(code);
			printf("0x%7X %s\n", handles[i], name);
		}
		printf("\n%s\n", "Use layout name or code as argument to disable it\n");
	} else if (argc > 1){
		if (argc > 2){
			DWORD time = strtol(args[2], NULL, 10);
			printf("Waiting %d ms\n", time);
			Sleep(time);
		}
		
		HKL target;
		if (args[1][0] == '0' && args[1][1] == 'x'){
			target = strtol(args[1], NULL, 16);
		} else {
			for (int i = 0; i < count; ++i){
				uint32_t code = (uint64_t)handles[i] & 0xFFFF;
				char* name = getLayoutName(code);
				if (strcmp(args[1], name) == 0){
					target = handles[i];
					break;
				}
			}
		}
		if (UnloadKeyboardLayout(target)){
			printf("%s\n", "Layout successfully removed");
		} else {
			printf("%s\n", "Failed to remove");
		}
		return 0;
	}

	return 0;
}
