{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp, tmp2:string;
begin
  regint (26);
  for i:=1 to 100 do begin
    repeat
      x:=randomtree2 (5, 1, 1, 1, 10, 0, 5, 0, 3, 0, 0, 10, 0, 0, 50, 50, 10);
      tmp:=displaytree2 (x, false, false);
      x:=randomtree2 (5, 1, 1, 1, 10, 0, 5, 0, 3, 0, 0, 10, 0, 0, 50, 50, 10);
      tmp2:=displaytree2 (x, false, false);
    until length (tmp)+length (tmp2)<=251;
    write ('?', tmp);
    case random (10) of
      0:write ('<');
      1:write ('>');
      2:write ('=');
      3:write ('<=');
      4:write ('>=');
      5:write ('<>');
      6:write ('->');
      7:write ('<-');
      8:write ('<<');
      9:write ('>>');
    end;
    writeln (tmp2);
  end;
end.