{$ifdef VER70}
{$A+,B-,D+,E-,F-,G+,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}
{$else}
{$A+,B-,C+,D+,E-,F-,G+,H+,I+,J+,K-,L+,M-,N+,O+,P-,Q+,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $00100000}
{$IMAGEBASE $00400000}
{$APPTYPE CONSOLE}
{$endif}
program macro;
uses testlib;
const eps=1.1e-6;
var jury, cont:extended;
    count:longint; 
begin
  count:=0;
  while not ans.seekeof do
    begin
      if ouf.seekeof then quit (_Wa, '���������� ����� 䠩�� ���⭨��');
      ans.sp;
      jury:=ans.readreal;
      cont:=ouf.readreal;
      inc (count);
      if abs (jury-cont)>eps then quit (_wa, '�訡�� � �᫥ #'+i2s (count)+
      ' (������ � 䠩�� ��� '+
        ans.spp +') �ॡ������� '+r2s (jury)+', � ����祭� '+r2s (cont));
    end;
  if not ouf.seekeof then quit (_wa, '����� ���ଠ�� � �⢥� ���⭨��');
  quit (_ok, '');
end.