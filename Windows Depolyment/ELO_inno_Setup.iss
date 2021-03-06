; Script generated by the Inno Script Studio Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{6D0E1A70-2965-4CA8-9612-21057800505D}
AppName=ELO
AppVersion=1.46
AppPublisherURL=http://www.chemie.tu-freiberg.de/~herbigm/ELO
AppSupportURL=http://www.chemie.tu-freiberg.de/~herbigm/ELO
AppUpdatesURL=http://www.chemie.tu-freiberg.de/~herbigm/ELO
DefaultDirName={pf}\ELO
DefaultGroupName=ELO
AllowNoIcons=yes
OutputDir=.
OutputBaseFilename=setup
SetupIconFile=Icon.ico
Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "deployment files\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
Source: "C:\Windows\Fonts\NotoKufiArabic-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Kufi Arabic Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoKufiArabic-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Kufi Arabic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoMono-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Mono"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoNaskhArabic-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Naskh Arabic Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoNaskhArabic-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Naskh Arabic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoNaskhArabicUI-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Naskh Arabic UI Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoNaskhArabicUI-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Naskh Arabic UI"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-BoldItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Bold Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-Condensed.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Condensed"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-CondensedBold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Condensed Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-CondensedBoldItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Condensed Bold Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-CondensedItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Condensed Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-Italic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-Light.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Light"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-LightItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Light Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSans-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArabic-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Arabic Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArabic-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Arabic Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArabicUI-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Arabic UI Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArabicUI-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Arabic UI Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArmenian-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Armenian Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansArmenian-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Armenian Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansGeorgian-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Georgian Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansGeorgian-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Georgian Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansHebrew-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Hebrew Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansHebrew-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Hebrew Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansLao-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Lao Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansLao-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Lao Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSansLisu-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Sans Lisu Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-BoldItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Bold Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-Condensed.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Condensed"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-CondensedBold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Condensed Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-CondensedBoldItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Condensed Bold Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-CondensedItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Condensed Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-Italic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-Light.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Light"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-LightItalic.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Light Italic"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerif-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifArmenian-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Armenian Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifArmenian-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Armenian Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifGeorgian-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Georgian Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifGeorgian-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Georgian Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifHebrew-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Hebrew Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifHebrew-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Hebrew Regular"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifLao-Bold.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Lao Bold"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "C:\Windows\Fonts\NotoSerifLao-Regular.ttf"; DestDir: "{fonts}"; FontInstall: "Noto Serif Lao Regular"; Flags: onlyifdoesntexist uninsneveruninstall

[Icons]
Name: "{group}\ELO"; Filename: "{app}\ELO-NG.exe"
Name: "{group}\{cm:UninstallProgram,ELO}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\ELO"; Filename: "{app}\ELO-NG.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\ELO"; Filename: "{app}\ELO-NG.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\ELO-NG.exe"; Description: "{cm:LaunchProgram,ELO}"; Flags: nowait postinstall skipifsilent

[ThirdParty]
UseRelativePaths=True
