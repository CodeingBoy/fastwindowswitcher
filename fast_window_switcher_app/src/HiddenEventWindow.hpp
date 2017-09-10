/***************************************************************************
**
** Copyright (C) 2017 Jochen Baier
** Contact: email@jochen-baier.
**
** This file is part of the FastWindowSwitcher

This program is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see < http://www.gnu.org/licenses/>.

Dieses Programm ist Freie Software : Sie k�nnen es unter den Bedingungen
der GNU General Public License, wie von der Free Software Foundation,
Version 3 der Lizenz oder(nach Ihrer Wahl) jeder neueren
ver�ffentlichten Version, weiterverbreiten und / oder modifizieren.

Dieses Programm wird in der Hoffnung, dass es n�tzlich sein wird, aber
OHNE JEDE GEW�HRLEISTUNG, bereitgestellt; sogar ohne die implizite
Gew�hrleistung der MARKTF�HIGKEIT oder EIGNUNG F�R EINEN BESTIMMTEN ZWECK.
Siehe die GNU General Public License f�r weitere Details.

Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
Programm erhalten haben.Wenn nicht, siehe < http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma  once

#include <memory>

#include <QWidget>

class QByteArray;
class QKeyEvent;

namespace FastWindowSwitcher
{
  class HiddenEventWindow : public QWidget
  {
    Q_OBJECT

  public:
    HiddenEventWindow();
    virtual bool nativeEvent(const QByteArray& eventType, void *message, long *result) override;

    Q_SLOT void BringToTop();
    Q_SIGNAL void HotKeyPressed();
    Q_SIGNAL void Aborted();
    Q_SIGNAL void KeyPressed(const QKeyEvent& p_keyEvent);
    Q_SIGNAL void ExplorerRestarted();

  protected:
    virtual bool event(QEvent* p_event) override;
    void keyPressEvent(QKeyEvent* p_event) override;

  private:
    quint32 m_taskbarRestartMessage;
  };

  using HiddenEventWindowPtr = std::unique_ptr<HiddenEventWindow>;
};