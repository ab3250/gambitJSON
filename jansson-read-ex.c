
//#include <util.h>
#include <jansson.h>
#include <string.h>

json_t *json;

int main(void){
    json_t *json,*json1;
    json_error_t error;
    char *data[52];
    int i;
    
    json1 = json_loads("{ \"cards\" : [\"0000\", \"0001\", \"0002\", \"0003\", \"0004\", \
         \"0005\", \"0006\", \"0007\", \"0008\", \"0009\", \"0010\", \"0011\", \"0012\", \
         \"0100\", \"0101\", \"0102\", \"0103\", \"0104\", \"0105\", \"0106\", \"0107\", \
         \"0108\", \"0109\", \"0110\", \"0111\", \"0112\", \"0200\", \"0201\", \"0202\", \
         \"0203\", \"0204\", \"0205\", \"0206\", \"0207\", \"0208\", \"0209\", \"0210\", \
         \"0211\", \"0212\", \"0300\", \"0301\", \"0302\", \"0303\", \"0304\", \"0305\", \
         \"0306\", \"0307\", \"0308\", \"0309\", \"0310\", \"0311\", \"0312\"]}",0,&error);
         
    json = json_object_get(json1, "cards");
    
    if(json == NULL)
    {
        fprintf(stderr, "error: null\n");
        json_decref(json);
        return 1;
    }

    // if(!json_is_array(json))
    // {
    //     fprintf(stderr, "error: root is not an array\n");
    //     json_decref(json);
    //     return 1;
    // }
    
    printf("\n%li\n",json_array_size(json));
    
    //int result = json_unpack(json, "{s:o}", "cards", &data);
    
    for(i = 0; i < json_array_size(json); i++)
    {
    //printf("%i",i);
       // json_t *data, *sha, *commit, *message;
        //const char *message_text;
       data[i] = json_string_value(json_array_get(json, i)); 
        // if(!json_is_object(data[i]))
        //     {
        //         fprintf(stderr, "error: commit data %d is not an object\n", i + 1);
        //         json_decref(json);
        //         return 1;
        //     }
        printf("%s\n", data[i]);
    }
   
}


