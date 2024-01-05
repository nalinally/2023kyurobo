# 本名刺基板の使い方

本基板名刺は、Arduinoにプログラムを書き込んで挿すことで、連打綱引きゲームができるようになります。
※動作確認はしておりません。あしからず。

## １．部品の実装
### 用意するもの
・[タクトスイッチ](https://akizukidenshi.com/catalog/g/gP-03647/)  2個 <br>
・[led](https://akizukidenshi.com/catalog/g/gI-11577/)  7個<br>
・[1ｋくらいの抵抗](https://akizukidenshi.com/catalog/g/gR-25102/)  7本<br>
### 実装例

[写真貼る]

## ２．Arduinoへプログラム書き込み

Arduino IDE を使って、プログラムをArduinoに書き込みます
※プログラムは、Arduino UNO R3 での動作を想定して書かれています

## ３．遊ぶ

### スタート方法

両者がスイッチを押すとカウントが始まり、その状態で3秒間押し続けて、真ん中のLEDが光るとゲームスタートです

### ゲーム中

ひたすらスイッチを連打します。最初は真ん中のLEDが光っていますが、より連打数が多いほうに徐々に引き寄せられていきます。

### ゲームの勝敗

自分に一番近いLEDを先に光らせたほうの勝利です。
