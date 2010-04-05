node system(r_1 : bool;
a_1_1 : bool;
a_1_2 : bool;
failure_1i : bool;
failure_2i : bool;
failure_3i : bool;
t_1 : bool;
chk_1 : bool) returns (ttt : bool;
suiv_I_de_tache_1_0 : bool;
suiv_R_de_tache_1_0 : bool;
suiv_A_1_de_tache_1_0 : bool;
suiv_A_2_de_tache_1_0 : bool;
suiv_B_1_de_tache_1_0 : bool;
suiv_A_3_de_tache_1_0 : bool;
suiv_B_2_de_tache_1_0 : bool;
suiv_B_3_de_tache_1_0 : bool;
suiv_T_de_tache_1_0 : bool;
suiv_memoire_de_ttt : bool);
var
   I_de_tache_1_0_Choix : bool;
   R_de_tache_1_0_Choix : bool;
   A_1_de_tache_1_0_Choix : bool;
   A_2_de_tache_1_0_Choix : bool;
   B_1_de_tache_1_0_Choix : bool;
   A_3_de_tache_1_0_Choix : bool;
   B_2_de_tache_1_0_Choix : bool;
   B_3_de_tache_1_0_Choix : bool;
   T_de_tache_1_0_Choix : bool;
   condition_de_I_de_tache_1_0_vers_R_de_tache_1_0_0 : bool;
   condition_de_R_de_tache_1_0_vers_A_1_de_tache_1_0_1 : bool;
   condition_de_R_de_tache_1_0_vers_A_2_de_tache_1_0_2 : bool;
   condition_de_R_de_tache_1_0_vers_A_3_de_tache_1_0_3 : bool;
   condition_de_A_1_de_tache_1_0_vers_A_2_de_tache_1_0_4 : bool;
   condition_de_A_1_de_tache_1_0_vers_A_3_de_tache_1_0_5 : bool;
   condition_de_A_2_de_tache_1_0_vers_A_1_de_tache_1_0_6 : bool;
   condition_de_A_2_de_tache_1_0_vers_A_3_de_tache_1_0_7 : bool;
   condition_de_A_3_de_tache_1_0_vers_A_1_de_tache_1_0_8 : bool;
   condition_de_A_3_de_tache_1_0_vers_A_2_de_tache_1_0_9 : bool;
   condition_de_A_1_de_tache_1_0_vers_B_1_de_tache_1_0_10 : bool;
   condition_de_A_1_de_tache_1_0_vers_B_2_de_tache_1_0_11 : bool;
   condition_de_A_1_de_tache_1_0_vers_B_3_de_tache_1_0_12 : bool;
   condition_de_A_2_de_tache_1_0_vers_B_1_de_tache_1_0_13 : bool;
   condition_de_A_2_de_tache_1_0_vers_B_2_de_tache_1_0_14 : bool;
   condition_de_A_2_de_tache_1_0_vers_B_3_de_tache_1_0_15 : bool;
   condition_de_A_3_de_tache_1_0_vers_B_1_de_tache_1_0_16 : bool;
   condition_de_A_3_de_tache_1_0_vers_B_2_de_tache_1_0_17 : bool;
   condition_de_A_3_de_tache_1_0_vers_B_3_de_tache_1_0_18 : bool;
   condition_de_B_1_de_tache_1_0_vers_T_de_tache_1_0_19 : bool;
   condition_de_B_2_de_tache_1_0_vers_T_de_tache_1_0_20 : bool;
   condition_de_B_3_de_tache_1_0_vers_T_de_tache_1_0_21 : bool;
   condition_de_B_1_de_tache_1_0_vers_B_2_de_tache_1_0_22 : bool;
   condition_de_B_1_de_tache_1_0_vers_B_3_de_tache_1_0_23 : bool;
   condition_de_B_2_de_tache_1_0_vers_B_1_de_tache_1_0_24 : bool;
   condition_de_B_2_de_tache_1_0_vers_B_3_de_tache_1_0_25 : bool;
   condition_de_B_3_de_tache_1_0_vers_B_1_de_tache_1_0_26 : bool;
   condition_de_B_3_de_tache_1_0_vers_B_2_de_tache_1_0_27 : bool;
   I_de_tache_1_0 : bool;
   R_de_tache_1_0 : bool;
   A_1_de_tache_1_0 : bool;
   A_2_de_tache_1_0 : bool;
   B_1_de_tache_1_0 : bool;
   A_3_de_tache_1_0 : bool;
   B_2_de_tache_1_0 : bool;
   B_3_de_tache_1_0 : bool;
   T_de_tache_1_0 : bool;
   memoire_de_ttt : bool;

let
   I_de_tache_1_0_Choix=true;
   R_de_tache_1_0_Choix=false;
   A_1_de_tache_1_0_Choix=false;
   A_2_de_tache_1_0_Choix=false;
   B_1_de_tache_1_0_Choix=false;
   A_3_de_tache_1_0_Choix=false;
   B_2_de_tache_1_0_Choix=false;
   B_3_de_tache_1_0_Choix=false;
   T_de_tache_1_0_Choix=false;
   condition_de_I_de_tache_1_0_vers_R_de_tache_1_0_0=if (I_de_tache_1_0) then (r_1) else false;
   condition_de_R_de_tache_1_0_vers_A_1_de_tache_1_0_1=if (R_de_tache_1_0) then (a_1_1 and not (a_1_2)) else false;
   condition_de_R_de_tache_1_0_vers_A_2_de_tache_1_0_2=if (R_de_tache_1_0) then (not (a_1_1) and a_1_2) else false;
   condition_de_R_de_tache_1_0_vers_A_3_de_tache_1_0_3=if (R_de_tache_1_0) then (((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2))) else false;
   condition_de_A_1_de_tache_1_0_vers_A_2_de_tache_1_0_4=if (A_1_de_tache_1_0) then (not (a_1_1) and a_1_2 and not (chk_1) and failure_1i) else false;
   condition_de_A_1_de_tache_1_0_vers_A_3_de_tache_1_0_5=if (A_1_de_tache_1_0) then (((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2)) and not (chk_1) and failure_1i) else false;
   condition_de_A_2_de_tache_1_0_vers_A_1_de_tache_1_0_6=if (A_2_de_tache_1_0) then (a_1_1 and not (a_1_2) and not (chk_1) and failure_2i) else false;
   condition_de_A_2_de_tache_1_0_vers_A_3_de_tache_1_0_7=if (A_2_de_tache_1_0) then (((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2)) and not (chk_1) and failure_2i) else false;
   condition_de_A_3_de_tache_1_0_vers_A_1_de_tache_1_0_8=if (A_3_de_tache_1_0) then (a_1_1 and not (a_1_2) and not (chk_1) and failure_3i) else false;
   condition_de_A_3_de_tache_1_0_vers_A_2_de_tache_1_0_9=if (A_3_de_tache_1_0) then (not (a_1_1) and a_1_2 and not (chk_1) and failure_3i) else false;
   condition_de_A_1_de_tache_1_0_vers_B_1_de_tache_1_0_10=if (A_1_de_tache_1_0) then (chk_1 and (a_1_1 and not (a_1_2))) else false;
   condition_de_A_1_de_tache_1_0_vers_B_2_de_tache_1_0_11=if (A_1_de_tache_1_0) then (chk_1 and (not (a_1_1) and a_1_2)) else false;
   condition_de_A_1_de_tache_1_0_vers_B_3_de_tache_1_0_12=if (A_1_de_tache_1_0) then (chk_1 and ((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2))) else false;
   condition_de_A_2_de_tache_1_0_vers_B_1_de_tache_1_0_13=if (A_2_de_tache_1_0) then (chk_1 and (a_1_1 and not (a_1_2))) else false;
   condition_de_A_2_de_tache_1_0_vers_B_2_de_tache_1_0_14=if (A_2_de_tache_1_0) then (chk_1 and (not (a_1_1) and a_1_2)) else false;
   condition_de_A_2_de_tache_1_0_vers_B_3_de_tache_1_0_15=if (A_2_de_tache_1_0) then (chk_1 and ((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2))) else false;
   condition_de_A_3_de_tache_1_0_vers_B_1_de_tache_1_0_16=if (A_3_de_tache_1_0) then (chk_1 and (a_1_1 and not (a_1_2))) else false;
   condition_de_A_3_de_tache_1_0_vers_B_2_de_tache_1_0_17=if (A_3_de_tache_1_0) then (chk_1 and (not (a_1_1) and a_1_2)) else false;
   condition_de_A_3_de_tache_1_0_vers_B_3_de_tache_1_0_18=if (A_3_de_tache_1_0) then (chk_1 and ((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2))) else false;
   condition_de_B_1_de_tache_1_0_vers_T_de_tache_1_0_19=if (B_1_de_tache_1_0) then (t_1) else false;
   condition_de_B_2_de_tache_1_0_vers_T_de_tache_1_0_20=if (B_2_de_tache_1_0) then (t_1) else false;
   condition_de_B_3_de_tache_1_0_vers_T_de_tache_1_0_21=if (B_3_de_tache_1_0) then (t_1) else false;
   condition_de_B_1_de_tache_1_0_vers_B_2_de_tache_1_0_22=if (B_1_de_tache_1_0) then (not (a_1_1) and a_1_2 and not (t_1) and failure_1i) else false;
   condition_de_B_1_de_tache_1_0_vers_B_3_de_tache_1_0_23=if (B_1_de_tache_1_0) then (((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2)) and not (t_1) and failure_1i) else false;
   condition_de_B_2_de_tache_1_0_vers_B_1_de_tache_1_0_24=if (B_2_de_tache_1_0) then (a_1_1 and not (a_1_2) and not (t_1) and failure_2i) else false;
   condition_de_B_2_de_tache_1_0_vers_B_3_de_tache_1_0_25=if (B_2_de_tache_1_0) then (((not (a_1_1) and not (a_1_2)) or (a_1_1 and a_1_2)) and not (t_1) and failure_2i) else false;
   condition_de_B_3_de_tache_1_0_vers_B_1_de_tache_1_0_26=if (B_3_de_tache_1_0) then (a_1_1 and not (a_1_2) and not (t_1) and failure_3i) else false;
   condition_de_B_3_de_tache_1_0_vers_B_2_de_tache_1_0_27=if (B_3_de_tache_1_0) then (not (a_1_1) and a_1_2 and not (t_1) and failure_3i) else false;
   I_de_tache_1_0=true->pre(suiv_I_de_tache_1_0);
   R_de_tache_1_0=false->pre(suiv_R_de_tache_1_0);
   A_1_de_tache_1_0=false->pre(suiv_A_1_de_tache_1_0);
   A_2_de_tache_1_0=false->pre(suiv_A_2_de_tache_1_0);
   B_1_de_tache_1_0=false->pre(suiv_B_1_de_tache_1_0);
   A_3_de_tache_1_0=false->pre(suiv_A_3_de_tache_1_0);
   B_2_de_tache_1_0=false->pre(suiv_B_2_de_tache_1_0);
   B_3_de_tache_1_0=false->pre(suiv_B_3_de_tache_1_0);
   T_de_tache_1_0=false->pre(suiv_T_de_tache_1_0);
   ttt=memoire_de_ttt;
   suiv_I_de_tache_1_0=if (I_de_tache_1_0) then (not (condition_de_I_de_tache_1_0_vers_R_de_tache_1_0_0)) else I_de_tache_1_0,
   suiv_R_de_tache_1_0=if (I_de_tache_1_0) then (condition_de_I_de_tache_1_0_vers_R_de_tache_1_0_0) else R_de_tache_1_0,
   suiv_A_1_de_tache_1_0=A_1_de_tache_1_0,
   suiv_A_2_de_tache_1_0=A_2_de_tache_1_0,
   suiv_B_1_de_tache_1_0=B_1_de_tache_1_0,
   suiv_A_3_de_tache_1_0=A_3_de_tache_1_0,
   suiv_B_2_de_tache_1_0=B_2_de_tache_1_0,
   suiv_B_3_de_tache_1_0=B_3_de_tache_1_0,
   suiv_T_de_tache_1_0=T_de_tache_1_0,
   suiv_memoire_de_ttt=ttt;
   memoire_de_ttt=false->pre(suiv_memoire_de_ttt);

tel;

