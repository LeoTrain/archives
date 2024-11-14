using Avalonia.Controls;
using Avalonia.Interactivity;
using System;

namespace grid.Views;

public partial class MainWindow : Window {
  public MainWindow() { InitializeComponent(); }

  private void OnButtonClick(object? sender, RoutedEventArgs e) {
    if ((DeziBox.IsChecked ?? false) || (DualBox.IsChecked ?? false) ||
        (HexaBox.IsChecked ?? false)) {
      string value = InputNumber.Text ?? string.Empty;

      if (IsNumber(value)) {
        if (DeziBox.IsChecked ?? false) {
          int nbr = int.Parse(value);
          string dezi = nbr.ToString();
          string dual = DecimalToByte(nbr, 2);
          string hexa = DecimalToByte(nbr, 16);
          DeziTextBlock.Text = "Dezi: " + dezi;
          DualTextBlock.Text = "Dual: " + dual;
          HexaTextBlock.Text = "Hexa: " + hexa;
        } else if (HexaBox.IsChecked ?? false) {
          int decimalValue = int.Parse(HexToDecimal(value));
          string dezi = decimalValue.ToString();
          string dual = DecimalToByte(decimalValue, 2);
          DeziTextBlock.Text = "Dezi: " + dezi;
          DualTextBlock.Text = "Dual: " + dual;
          HexaTextBlock.Text = "Hexa: " + value;
        } else if (DualBox.IsChecked ?? false) {
          int decimalValue = int.Parse(DualToDecimal(value));
          if (decimalValue != 0) {
            string dezi = decimalValue.ToString();
            string hexa = DecimalToByte(decimalValue, 16);
            DeziTextBlock.Text = "Dezi: " + dezi;
            DualTextBlock.Text = "Dual: " + value;
            HexaTextBlock.Text = "Hexa: " + hexa;
          }
        }
      }
    }
  }

  private void OnCheckBoxChecked(object sender, RoutedEventArgs e) {
    if (sender == DeziBox) {
      DualBox.IsChecked = false;
      HexaBox.IsChecked = false;
    } else if (sender == DualBox) {
      DeziBox.IsChecked = false;
      HexaBox.IsChecked = false;
    } else if (sender == HexaBox) {
      DeziBox.IsChecked = false;
      DualBox.IsChecked = false;
    }
  }
}
