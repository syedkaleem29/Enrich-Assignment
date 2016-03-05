//
//  Created by R.M.D. Engineering College  on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//
struct person
{
    char *contact_person_id;
    char *first_name;
    char *last_name;
    char *email;
};
struct group
{
    struct person client[2];
    char *contact_id;
    char *contact_name;
    char *street;
    char *area;
    char *city;
}contact[2];
