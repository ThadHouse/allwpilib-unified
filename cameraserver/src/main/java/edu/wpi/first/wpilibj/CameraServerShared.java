package edu.wpi.first.wpilibj;

import edu.wpi.first.wpilibj.sharedinterfaces.CameraServerErrorFunc;
import edu.wpi.first.wpilibj.sharedinterfaces.DriverStationErrorFunc;
import edu.wpi.first.wpilibj.sharedinterfaces.ReportFunc;
import edu.wpi.first.wpilibj.sharedinterfaces.RobotMainThreadIdFunc;
import edu.wpi.first.wpilibj.sharedinterfaces.VisionRunnerErrorFunc;

public class CameraServerShared {
  private static CameraServerShared cameraServerShared = null;

  /**
   * get the CameraServerShared object.
   */
  public static synchronized CameraServerShared getCameraServerShared() {
    if (cameraServerShared == null) {
      cameraServerShared = new CameraServerShared();
      cameraServerShared.m_reportAxisCamera = (int id) -> { };
      cameraServerShared.m_reportUsbCamera = (int id) -> { };
      cameraServerShared.m_reportVideoServer = (int id) -> { };
      cameraServerShared.m_setCameraServerError = (String err) -> { };
      cameraServerShared.m_setVisionRunnerError = (String err) -> { };
      cameraServerShared.m_reportDriverStationError = (String err) -> { };
      cameraServerShared.m_robotMainThreadId = () -> {
        return null;
      };
    }
    return cameraServerShared;
  }

  /**
   * set the CameraServerShared object.
   */
  public static synchronized void setCameraServerShared(CameraServerShared shared) {
    cameraServerShared = shared;
  }

  private ReportFunc m_reportUsbCamera;
  private ReportFunc m_reportAxisCamera;
  private ReportFunc m_reportVideoServer;
  private CameraServerErrorFunc m_setCameraServerError;
  private VisionRunnerErrorFunc m_setVisionRunnerError;
  private DriverStationErrorFunc m_reportDriverStationError;
  private RobotMainThreadIdFunc m_robotMainThreadId;

  /**
   * get the main thread id func.
   *
   * @return the robotMainThreadId
   */
  public RobotMainThreadIdFunc getRobotMainThreadId() {
    return m_robotMainThreadId;
  }

  /**
   * set the main thread id func.
   *
   * @param robotMainThreadId the robotMainThreadId to set
   */
  public void setRobotMainThreadId(RobotMainThreadIdFunc robotMainThreadId) {
    this.m_robotMainThreadId = robotMainThreadId;
  }

  /**
   * get the reportDriverStationError func.
   *
   * @return the reportDriverStationError
   */
  public DriverStationErrorFunc getReportDriverStationError() {
    return m_reportDriverStationError;
  }

  /**
   * set the reportDriverStationError func.
   *
   * @param reportDriverStationError the reportDriverStationError to set
   */
  public void setReportDriverStationError(DriverStationErrorFunc reportDriverStationError) {
    this.m_reportDriverStationError = reportDriverStationError;
  }

  /**
   * get the setVisionRunnerError func.
   *
   * @return the setVisionRunnerError
   */
  public VisionRunnerErrorFunc getSetVisionRunnerError() {
    return m_setVisionRunnerError;
  }

  /**
   * set the setVisionRunnerError func.
   *
   * @param setVisionRunnerError the setVisionRunnerError to set
   */
  public void setSetVisionRunnerError(VisionRunnerErrorFunc setVisionRunnerError) {
    this.m_setVisionRunnerError = setVisionRunnerError;
  }

  /**
   * get the setCameraServerError func.
   *
   * @return the setCameraServerError
   */
  public CameraServerErrorFunc getSetCameraServerError() {
    return m_setCameraServerError;
  }

  /**
   * set the setCameraServerError func.
   *
   * @param setCameraServerError the setCameraServerError to set
   */
  public void setSetCameraServerError(CameraServerErrorFunc setCameraServerError) {
    this.m_setCameraServerError = setCameraServerError;
  }

  /**
   * get the reportVideoServer func.
   *
   * @return the reportVideoServer
   */
  public ReportFunc getReportVideoServer() {
    return m_reportVideoServer;
  }

  /**
   * set the reportVideoServer func.
   *
   * @param reportVideoServer the reportVideoServer to set
   */
  public void setReportVideoServer(ReportFunc reportVideoServer) {
    this.m_reportVideoServer = reportVideoServer;
  }

  /**
   * get the reportAxisCamera func.
   *
   * @return the reportAxisCamera
   */
  public ReportFunc getReportAxisCamera() {
    return m_reportAxisCamera;
  }

  /**
   * set the reportAxisCamera func.
   *
   * @param reportAxisCamera the reportAxisCamera to set
   */
  public void setReportAxisCamera(ReportFunc reportAxisCamera) {
    this.m_reportAxisCamera = reportAxisCamera;
  }

  /**
   * get the reportUsbCamera func.
   *
   * @return the reportUsbCamera
   */
  public ReportFunc getReportUsbCamera() {
    return m_reportUsbCamera;
  }

  /**
   * set the reportUsbCamera func.
   *
   * @param reportUsbCamera the reportUsbCamera to set
   */
  public void setReportUsbCamera(ReportFunc reportUsbCamera) {
    this.m_reportUsbCamera = reportUsbCamera;
  }
}
