
//#include <util.h>
#include <jansson.h>
#include <string.h>

json_t *json;

int main(void){
    json_t *json;
    char* s = NULL;
    json_t *root = json_object();
    json_t *json_arr = json_array();
    json_object_set_new( root, "destID", json_integer( 1 ) );
    
    //json = json_pack("i", 42);
    s = json_dumps(root, 0);
    //print_json(json);
    printf("\n%s\n", s);   
}


