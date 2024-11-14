using System;

namespace grid {
internal class CZahl {

  private long zahl;
  private string Ziffern = "0123456789ABCDEF";

  bool ZahlEingabe(string zahl, int b) {
    if (b < 2 || b > 16)
      return false;
    for (int i = 0; i < zahl.Length; i++) {
      bool merken = false;
      for (int j = 0; j < b; j++)
        if (zahl[i] == zahl[j])
          merken = true;
      if (merken == false) {
        Console.WriteLine("Falsche Eingabe !!");
        return false;
      }
    }
    return true;
  }
}
}
