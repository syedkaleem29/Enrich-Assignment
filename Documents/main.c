//
//  main.c
//  syed2
//
//  Created by R.M.D. Engineering College  on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    char *contact_personid;
    char *firstname;
    char *secondname;
}p;
struct contact
{
    char *contact_id;
    char *name;
    char *street;
    char *area;
    char *city;
    struct person p[2];
    
}c;
char* tostring(char *res,int flag)
{
    int i=2;
    strcat(res,"[\n\t{\n\t\"ID\":\"");
    strcat(res, c.contact_id);
    strcat(res,"\",\n\t\t\"Name\":\"");
    strcat(res,c.name);
    strcat(res,"\",\n\t\t\"Street\":\"");
    strcat(res,c.street);
    strcat(res,"\",\n\t\t\"Area\":\"");
    strcat(res,c.area);
    strcat(res,"\",\n\t\t\"City\":\"");
    strcat(res,c.city);
    strcat(res,"\",\n\t\t\"Contact\":\n\t\t[");
    for(i=0;i<2;i++)
    {
        strcat(res,"\n\t\t{\n\t\t\t\"Contact Person ID\":\"");
        strcat(res, c.p[i].contact_personid);
        strcat(res,"\",\n\t\t\t\"First Name\":\"");
        strcat(res,c.p[i].firstname);
        strcat(res,"\",\n\t\t\t\"Second Name\":\"");
        strcat(res,c.p[i].secondname);
        strcat(res,"\n\t\t}");
        
    }
    strcat(res,"\",\n\t\t]\n\t}\n");
    strcat(res,"]\n");
    return res;
}
int main(int argc, const char * argv[])
{
    // insert code here...
    char *res=malloc(sizeof(char));
    c.contact_id="12";
    c.name="kaleem";
    c.street="123 street";
    c.area="Gumidipoondi";
    c.city="Kavaraipettai";
    c.p[0].contact_personid="123";
    c.p[0].firstname="syed";
    c.p[0].secondname="kaleem";
    c.p[1].contact_personid="1234";
    c.p[1].firstname="syedk";
    c.p[1].secondname="Skaleem";
    res=tostring(res,0);
    printf("%s",res);
    return 0;
}
