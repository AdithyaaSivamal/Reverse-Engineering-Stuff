/*
The code below is provided for reference for the Basic_Password_Challenge write-up.
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<Windows.h>
#include<winbase.h>
#include<wincon.h>
#include<windef.h>
#include<winnt.h>
// Add the necessary include path for the system headers

/* process_user_inputs(pp_argC,pp_argV,initial_narrow_environments,in_R9) */

#include <cstddef>
int main(int argc,char **argv,char **envplong R9)

{
  process_user_inputs(argc,argv,envp,R9);
  return 0;
}

void process_user_inputs(undefined8 param_1,undefined8 param_2,undefined8 param_3, long param_4)

{
  byte bVar1;
  undefined8 uVar2;
  long uVar3;
  undefined6 uVar4
  undefined auVar5 [12];
  undefined auVar6 [12];
  FILE *_File;
  long *plVar7;
  char *isCorrectPassword;
  undefined8 userInput_param2;
  undefined4 *p_username;
  uint uVar8;
  long uVar9;
  long uVar10;
  long uVar11;
  undefined8 userInput_param3;
  short sVar12;
  undefined auVar13 [16];
  undefined auVar16 [16];
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  undefined auStack_b8 [32];
  uint local_98 [4];
  undefined user_Input_buffer [4];
  undefined4 auStack_84 [3];
  undefined local_78 [16];
  undefined local_68 [16];
  undefined local_58 [16];
  undefined local_48 [16];
  undefined local_38 [16];
  undefined4 local_28;
  long local_18;
  undefined auVar14 [16];
  undefined auVar15 [16];
  undefined auVar17 [16];
  undefined auVar18 [16];
  undefined uVar19;
  undefined2 uVar20;
  undefined4 dereferenced_username;

  local_18 = sessionCookieIndicator ^ (long)auStack_b8;
  SetConsoleTitleA("Basic Crackme challenge, Made By Cutypie");
  _user_Input_buffer = ZEXT816(0);
  uVar9 = 0;
  local_28 = 0;
  local_78 = _user_Input_buffer;
  local_68 = _user_Input_buffer;
  local_58 = _user_Input_buffer;
  local_48 = _user_Input_buffer;
  local_38 = _user_Input_buffer;
  display_outcome("Username: ",param_2,param_3,param_4);
  _File = (FILE *)__acrt_iob_func(0);
                    /* store '_File' in 'locate_88' */
  fgets(user_Input_buffer,100,_File);
                    /* p_username points to char[] of username in user_input_buffer */
  p_username = (undefined4 *)user_Input_buffer;
  uVar11 = 0xffffffffffffffff;
  do {
    uVar10 = uVar11;
    uVar11 = uVar10 + 1;
                    /* loop through user_input_buffer until '\0' found.
                       uVar14 will overflow  */
  } while (user_Input_buffer[uVar10 + 1] != '\0');
  printf_password(long *)cout_exref,"Enter your password: ");
  plVar7 = long *)std::basic_istream<>::operator>>((basic_istream<> *)cin_exref,local_98);
  bVar1 = *(byte *)(long)*(int *)(*plVar7 + 4) + 0x10 + long)plVar7);
  while ((bVar1 & 6) != 0) {
    std::basic_ios<>::clear
              ((basic_ios<> *)(long)*(int *)(*long *)cin_exref + 4) + long)cin_exref)
               ,0,false);
    std::basic_istream<>::ignore((basic_istream<> *)cin_exref,0x7fffffffffffffff,10);
    printf_password(long *)cout_exref,"Invalid input. Please enter a valid unsigned integer: ")
    ;
    plVar7 = long *)std::basic_istream<>::operator>>((basic_istream<> *)cin_exref,local_98);
    param_4 = long)*(int *)(*plVar7 + 4);
    bVar1 = *(byte *)(param_4 + 0x10 + long)plVar7);
  }
  userInput_param3 = 10;
  userInput_param2 = 0x7fffffffffffffff;
  std::basic_istream<>::ignore((basic_istream<> *)cin_exref,0x7fffffffffffffff,10);
  if (user_Input_buffer + uVar10 + 1 < user_Input_buffer) {
    uVar11 = uVar9;
  }
  if ((uVar11 != 0) && (7 < uVar11)) {
    iVar25 = 0;
    iVar26 = 0;
    iVar27 = 0;
    iVar28 = 0;
    iVar21 = 0;
    iVar22 = 0;
    iVar23 = 0;
    iVar24 = 0;
    do {
      dereferenced_username = *p_username;
      uVar9 = uVar9 + 8;
      uVar19 = (undefined)((uint)dereferenced_username >> 0x18);
      uVar20 = CONCAT11(uVar19,uVar19);
      uVar19 = (undefined)((uint)dereferenced_username >> 0x10);
      uVar2 = CONCAT35(CONCAT21(uVar20,uVar19),CONCAT14(uVar19,dereferenced_username));
      uVar19 = (undefined)((uint)dereferenced_username >> 8);
      uVar4 = CONCAT51(CONCAT41((int)((long)uVar2 >> 0x20),uVar19),uVar19);
      sVar12 = CONCAT11((char)dereferenced_username,(char)dereferenced_username);
      uVar3 = CONCAT62(uVar4,sVar12);
      auVar15._8_4_ = 0;
      auVar15._0_8_ = uVar3;
      auVar15._12_2_ = uVar20;
      auVar15._14_2_ = uVar20;
      uVar20 = (undefined2)((long)uVar2 >> 0x20);
      auVar14._12_4_ = auVar15._12_4_;
      auVar14._8_2_ = 0;
      auVar14._0_8_ = uVar3;
      auVar14._10_2_ = uVar20;
      auVar13._10_6_ = auVar14._10_6_;
      auVar13._8_2_ = uVar20;
      auVar13._0_8_ = uVar3;
      uVar20 = (undefined2)uVar4;
      auVar5._4_8_ = auVar13._8_8_;
      auVar5._2_2_ = uVar20;
      auVar5._0_2_ = uVar20;
      iVar25 = iVar25 + ((int)sVar12 >> 8);
      iVar26 = iVar26 + (auVar5._0_4_ >> 0x18);
      iVar27 = iVar27 + (auVar13._8_4_ >> 0x18);
      iVar28 = iVar28 + (auVar14._12_4_ >> 0x18);
      dereferenced_username = p_username[1];
      uVar19 = (undefined)((uint)dereferenced_username >> 0x18);
      uVar20 = CONCAT11(uVar19,uVar19);
      uVar19 = (undefined)((uint)dereferenced_username >> 0x10);
      uVar2 = CONCAT35(CONCAT21(uVar20,uVar19),CONCAT14(uVar19,dereferenced_username));
      uVar19 = (undefined)((uint)dereferenced_username >> 8);
      uVar4 = CONCAT51(CONCAT41((int)((long)uVar2 >> 0x20),uVar19),uVar19);
      sVar12 = CONCAT11((char)dereferenced_username,(char)dereferenced_username);
      uVar3 = CONCAT62(uVar4,sVar12);
      p_username = p_username + 2;
      auVar18._8_4_ = 0;
      auVar18._0_8_ = uVar3;
      auVar18._12_2_ = uVar20;
      auVar18._14_2_ = uVar20;
      uVar20 = (undefined2)((long)uVar2 >> 0x20);
      auVar17._12_4_ = auVar18._12_4_;
      auVar17._8_2_ = 0;
      auVar17._0_8_ = uVar3;
      auVar17._10_2_ = uVar20;
      auVar16._10_6_ = auVar17._10_6_;
      auVar16._8_2_ = uVar20;
      auVar16._0_8_ = uVar3;
      uVar20 = (undefined2)uVar4;
      auVar6._4_8_ = auVar16._8_8_;
      auVar6._2_2_ = uVar20;
      auVar6._0_2_ = uVar20;
      iVar21 = iVar21 + ((int)sVar12 >> 8);
      iVar22 = iVar22 + (auVar6._0_4_ >> 0x18);
      iVar23 = iVar23 + (auVar16._8_4_ >> 0x18);
      iVar24 = iVar24 + (auVar17._12_4_ >> 0x18);
    } while (uVar9 != (uVar11 & 0xfffffffffffffff8));
    uVar9 = (long)(uint)(iVar21 + iVar25 + iVar23 + iVar27 + iVar22 + iVar26 + iVar24 + iVar28)
    ;
  }
  uVar8 = (uint)uVar9;
  for (; p_username != (undefined4 *)(user_Input_buffer + uVar10 + 1);
      p_username = (undefined4 *)(long)p_username + 1)) {
    uVar8 = (int)uVar9 + (int)*(char *)p_username;
    uVar9 = (long)uVar8;
  }
  isCorrectPassword = "Correct Password!\n";
  if (local_98[0] != uVar8) {
    isCorrectPassword = "Bad\n";
  }
  display_outcome(isCorrectPassword,userInput_param2,userInput_param3,param_4);
  FUN_140001510(local_18 ^ (long)auStack_b8);


  return;
}
