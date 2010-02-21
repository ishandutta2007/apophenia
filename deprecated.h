/**\file */ //For Doxygen.
/* Copyright (c) 2010 by Ben Klemens.  Licensed under the modified GNU GPL v2; see COPYING and COPYING2.  */

double * apop_data_ptr_it(apop_data *in, const size_t row, const char* col);
double * apop_data_ptr_ti(apop_data *in,const  char* row,const  int col);
double * apop_data_ptr_tt(apop_data *in,const  char *row,const  char* col);
double apop_data_get_it(const apop_data *in,const  size_t row,const  char* col);
double apop_data_get_ti(const apop_data *in,const  char* row,const  int col);
double apop_data_get_tt(const apop_data *in,const  char *row,const  char* col);
void apop_data_set_ti(apop_data *in,const  char* row,const  int col,const  double data);
void apop_data_set_it(apop_data *in,const  size_t row,const  char* col,const  double data);
void apop_data_set_tt(apop_data *in,const  char *row,const  char* col,const  double data);



/** Add a settings group. 
  \deprecated{Use \ref Apop_model_add_group instead.}
  You will need to provide arguments for the specific settings group you
  are dealing with, such as <tt>apop_mle_settings_alloc</tt>, <tt>apop_lm_settings_alloc</tt>, <tt>apop_histogram_settings_alloc</tt>. */
#define Apop_settings_add_group(model, type, ...)  \
    apop_settings_group_alloc(model, #type, type ## _settings_free, type ## _settings_copy, type ##_settings_alloc (__VA_ARGS__)); 

#define APOP_SETTINGS_ADD_GROUP Apop_settings_add_group

apop_rank_settings *apop_rank_settings_alloc(void *ignoreme);
apop_histogram_settings *apop_histogram_settings_alloc(apop_data *data, int bins);
apop_mle_settings *apop_mle_settings_alloc(apop_model *model);


#define apop_ls_settings apop_lm_settings
#define apop_ls_settings_init apop_lm_settings_init
#define apop_ls_settings_copy apop_lm_settings_copy
#define apop_ls_settings_free apop_lm_settings_free

#define apop_wls apop_ols
#define apop_multinomial_probit apop_probit
