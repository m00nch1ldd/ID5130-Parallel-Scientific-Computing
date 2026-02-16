! comments
! My first Fortran program

! program main
!     implicit none
!     character(len=128) :: myname

!     write(*,*) 'Please enter your name: '
!     read (*,*) myname
!     write(*,*) 'Hello ',trim(myname), '!, Welcome to Fortran!'
! end program main

!Array - 1D operations

program arr 
    implicit none
    integer, parameter :: n=5
    write(*,*) n
    ! n=6 -> error: parameter is read only after initialization
    ! write(*,*) n

end program arr