using Avalonia.Controls;
using Avalonia.Interactivity;
using System;

namespace grid.Views {
public partial class MainWindow : Window {
  private bool IsNumber(string str) {
    if (string.IsNullOrEmpty(str))
      return false;
    foreach (char c in str) {
      if (!char.IsDigit(c))
        return false;
    }
    return true;
  }

  private bool IsDezi(string value) {
    bool returnValue = true;
    foreach (char nbr in value) {
      if (nbr < '0' && nbr > '9') {
        returnValue = false;
      }
    }
    return returnValue;
  }

  private bool IsHexa(string value) {
    bool returnValue = true;
    foreach (char nbr in value) {
      if ((nbr < '0' && nbr > '9') || (nbr < 'A' && nbr > 'F')) {
        returnValue = false;
      }
    }
    return returnValue;
  }

  private bool IsDual(string value) {
    bool returnValue = true;
    foreach (char nbr in value) {
      if (nbr < '0' && nbr > '1') {
        returnValue = false;
      }
    }
    return returnValue;
  }

  private string DecimalToByte(int nbr, short b) {
    if (IsDezi(nbr.ToString())) {
      string lib = "0123456789ABCDEF";
      int rest = 0;
      string output = "";
      while (nbr > 0) {
        rest = nbr % b;
        nbr = nbr / b;
        output = lib[rest] + output;
      }
      if (output == "") {
        output = "0";
      }
      return output;
    } else {
      return "";
    }
  }

  private string HexToDecimal(string hex) {
    if (IsHexa(hex)) {
      int decimalValue = 0;
      int length = hex.Length;
      for (int i = 0; i < length; i++) {
        char hexChar = hex[i];
        int value;
        if (hexChar >= '0' && hexChar <= '9') {
          value = hexChar - '0';
        } else if (hexChar >= 'A' && hexChar <= 'F') {
          value = hexChar - 'A' + 10;
        } else {
          throw new ArgumentException("Invalid hex Char");
        }
        decimalValue += value * (int)Math.Pow(16, length - i - 1);
      }
      return decimalValue.ToString();
    } else {
      return "0";
    }
  }

  private string DualToDecimal(string dual) {
    int decimalValue = 0;
    if (IsDual(dual) == true) {
      int length = dual.Length;
      for (int i = 0; i < length; i++) {
        char dualChar = dual[length - 1 - i];
        int val;
        if (dualChar == '0' || dualChar == '1') {
          val = dualChar - '0';
          decimalValue += val * (int)Math.Pow(2, i);
        }
      }
    }
    return decimalValue.ToString();
  }
}}
