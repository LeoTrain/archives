namespace MyApp {
internal partial class Piscine {

  static string ft_strcapitalize(string str) {
    bool isNextCapitalized = true;
    string newStr = "";
    foreach (char c in str) {
      if (isNextCapitalized) {
        newStr += ((char)22 + c);
      } else {
        newStr += c;
      }
    }
    return newStr;
  }

  static int ft_str_is_numeric(string str) {
    if (str.Length == 0) {
      return 1;
    }
    int isNumeric = 1;
    foreach (char c in str) {
      bool isNumber = (char)48 <= c && c <= (char)57;
      if (!isNumber) {
        isNumeric = 0;
      }
    }
    return isNumeric;
  }

  static int ft_str_is_alpha(string str) {
    if (str.Length == 0) {
      return 1;
    }
    int isAlpha = 1;
    foreach (char c in str) {
      bool isUpper = (char)97 <= c && c <= (char)122;
      bool isLower = (char)65 <= c && c <= (char)90;
      if (!isUpper && !isLower) {
        isAlpha = 0;
      }
    }
    return isAlpha;
  }

  static void ft_strcpy(ref string dest, string src) {
    string new_dest = "";
    if (src.Count() > 0) {
      for (int i = 0; i < src.Length; i++) {
        new_dest += src[i];
      }
      for (int i = src.Count(); i < dest.Length; i++) {
        new_dest += dest[i];
      }
      dest = new_dest;
    } else {
      dest = "";
    }
  }

  static void ft_strncpy(ref string dest, string src, int n) {
    string new_dest = "";
    for (int i = 0; i < n && i < src.Length; i++) {
      new_dest += src[i];
    }
    if (n > src.Length) {
      new_dest += new string('\0', n - src.Length);
    }
    dest = new_dest;
  }
}
}
