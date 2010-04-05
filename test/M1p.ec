node system(req1 : bool;
go1 : bool;
stop1 : bool;
G2 : bool) returns (gnt1 : bool;
suiv_I_de_M1_0 : bool;
suiv_W_de_M1_0 : bool;
suiv_C_de_M1_0 : bool;
suiv_G_de_M1_0 : bool;
suiv_I_de_obs_1 : bool;
suiv_E_de_obs_1 : bool;
suiv_memoire_de_gnt1 : bool);
var
   I_de_M1_0_Choix : bool;
   W_de_M1_0_Choix : bool;
   C_de_M1_0_Choix : bool;
   G_de_M1_0_Choix : bool;
   condition_de_I_de_M1_0_vers_W_de_M1_0_0 : bool;
   condition_de_I_de_M1_0_vers_G_de_M1_0_1 : bool;
   condition_de_W_de_M1_0_vers_C_de_M1_0_2 : bool;
   condition_de_C_de_M1_0_vers_G_de_M1_0_3 : bool;
   condition_de_C_de_M1_0_vers_I_de_M1_0_4 : bool;
   condition_de_G_de_M1_0_vers_I_de_M1_0_5 : bool;
   I_de_obs_1_Choix : bool;
   E_de_obs_1_Choix : bool;
   condition_de_I_de_obs_1_vers_E_de_obs_1_0 : bool;
   condition_de_E_de_obs_1_vers_E_de_obs_1_1 : bool;
   I_de_M1_0 : bool;
   W_de_M1_0 : bool;
   C_de_M1_0 : bool;
   G_de_M1_0 : bool;
   I_de_obs_1 : bool;
   E_de_obs_1 : bool;
   memoire_de_gnt1 : bool;
   
let
   I_de_M1_0_Choix=true;
   W_de_M1_0_Choix=false;
   C_de_M1_0_Choix=false;
   G_de_M1_0_Choix=false;
   condition_de_I_de_M1_0_vers_W_de_M1_0_0=if (I_de_M1_0) then (req1 and not (go1)) else false;
   condition_de_I_de_M1_0_vers_G_de_M1_0_1=if (I_de_M1_0) then (req1 and go1) else false;
   condition_de_W_de_M1_0_vers_C_de_M1_0_2=if (W_de_M1_0) then go1 else false;
   condition_de_C_de_M1_0_vers_G_de_M1_0_3=if (C_de_M1_0) then not (stop1) else false;
   condition_de_C_de_M1_0_vers_I_de_M1_0_4=if (C_de_M1_0) then stop1 else false;
   condition_de_G_de_M1_0_vers_I_de_M1_0_5=if (G_de_M1_0) then stop1 else false;
   I_de_obs_1_Choix=true;
   E_de_obs_1_Choix=false;
   condition_de_I_de_obs_1_vers_E_de_obs_1_0=if (I_de_obs_1) then (gnt1 and G2) else false;
   condition_de_E_de_obs_1_vers_E_de_obs_1_1=if (E_de_obs_1) then true else false;
   I_de_M1_0=true->pre(suiv_I_de_M1_0);
   W_de_M1_0=false->pre(suiv_W_de_M1_0);
   C_de_M1_0=false->pre(suiv_C_de_M1_0);
   G_de_M1_0=false->pre(suiv_G_de_M1_0);
   I_de_obs_1=true->pre(suiv_I_de_obs_1);
   E_de_obs_1=false->pre(suiv_E_de_obs_1);
   gnt1=if (I_de_M1_0) then false else if (W_de_M1_0) then false else if (C_de_M1_0) then (go1 and req1) else if (G_de_M1_0) then 
true else memoire_de_gnt1;
   suiv_I_de_M1_0=if (I_de_M1_0) then not ((condition_de_I_de_M1_0_vers_W_de_M1_0_0 or condition_de_I_de_M1_0_vers_G_de_M1_0_1))
 else if (C_de_M1_0) then condition_de_C_de_M1_0_vers_I_de_M1_0_4 else if (G_de_M1_0) then condition_de_G_de_M1_0_vers_I_de_M1_0_5
 else I_de_M1_0;
   suiv_W_de_M1_0=if (I_de_M1_0) then condition_de_I_de_M1_0_vers_W_de_M1_0_0 else if (W_de_M1_0) then not (
condition_de_W_de_M1_0_vers_C_de_M1_0_2) else W_de_M1_0;
   suiv_C_de_M1_0=if (W_de_M1_0) then condition_de_W_de_M1_0_vers_C_de_M1_0_2 else if (C_de_M1_0) then not ((
condition_de_C_de_M1_0_vers_G_de_M1_0_3 or condition_de_C_de_M1_0_vers_I_de_M1_0_4)) else C_de_M1_0;
   suiv_G_de_M1_0=if (I_de_M1_0) then condition_de_I_de_M1_0_vers_G_de_M1_0_1 else if (C_de_M1_0) then 
condition_de_C_de_M1_0_vers_G_de_M1_0_3 else if (G_de_M1_0) then not (condition_de_G_de_M1_0_vers_I_de_M1_0_5) else G_de_M1_0;
   suiv_I_de_obs_1=if (I_de_obs_1) then not (condition_de_I_de_obs_1_vers_E_de_obs_1_0) else I_de_obs_1;
   suiv_E_de_obs_1=if (I_de_obs_1) then condition_de_I_de_obs_1_vers_E_de_obs_1_0 else if (E_de_obs_1) then true else E_de_obs_1;
   suiv_memoire_de_gnt1=gnt1;
   memoire_de_gnt1=false->pre(suiv_memoire_de_gnt1);
   
tel;

