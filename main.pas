program studenti;
type
  articol = record
    nume: string;
    data: record
      zi, luna, an: integer;
    end;
    nr_carnet: integer;
    note: array[1..3] of real;
  end;
var
  varsta: integer;
  n, i, max_varsta, poz_max: integer;
  lista: array[1..100] of articol;
  exista, gasit: boolean;
  media, suma, medie_grupa: real;
begin
  writeln('Introduceti numarul de studenti din lista:');
  readln(n);
  writeln('Introduceti datele despre studenti:');
  for i := 1 to n do
  begin
    writeln('Studentul ', i, ':');
    writeln('Nume:');
    readln(lista[i].nume);
    writeln('Data nasterii (zi, luna, an):');
    readln(lista[i].data.zi, lista[i].data.luna, lista[i].data.an);
    writeln('Numarul carnetului de student:');
    readln(lista[i].nr_carnet);
    writeln('Notele (trei valori separate prin spatiu):');
    readln(lista[i].note[1], lista[i].note[2], lista[i].note[3]);
  end;
  // 1. Determinam numele studentului cu varsta maxima
  max_varsta := 0;
  poz_max := 0;
  for i := 1 to n do
  begin
    // Calculam varsta studentului in ani
    varsta := 2023 - lista[i].data.an;
    if lista[i].data.luna > 11 then
      varsta := varsta - 1; // Nu si-a sarbatorit inca ziua de nastere
    if varsta > max_varsta then
    begin
      max_varsta := varsta;
      poz_max := i;
    end;
  end;
  writeln('Numele studentului cu varsta maxima este: ', lista[poz_max].nume);
  // 2. Verificam daca exista persoane cu media notelor mai mica ca 5
  exista := false;
  i := 1;
  while (not exista) and (i <= n) do
  begin
    // Calculam media notelor studentului
    media := (lista[i].note[1] + lista[i].note[2] + lista[i].note[3]) / 3;
    if media < 5 then
      exista := true;
    i := i + 1;
  end;
  if exista then
    writeln('In lista exista persoane cu media notelor mai mica ca 5')
  else
    writeln('In lista nu exista persoane cu media notelor mai mica ca 5');
  // 3. Calculam media generala a grupei
  suma := 0;
  for i := 1 to n do
  begin
    // Calculam media notelor studentului
    media := (lista[i].note[1] + lista[i].note[2] + lista[i].note[3]) / 3;
    suma := suma + media;
  end;
  medie_grupa := suma / n;
  writeln('Media generala a grupei este: ', medie_grupa:0:2);
end.
