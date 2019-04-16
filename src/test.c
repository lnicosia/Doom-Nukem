{
	new_vz.x = vxs(vxs(render->vz1.x,render->vz1.y, render->vz2.x,render->vz2.y), (render->vz1.y)-(render->vz2.y),
			vxs(-render->near_side,render->near_z, render->-far_side,render->far_z), (render->near_z)-(render->far_z))
		/ vxs((render->vz1.x)-(render->vz2.x), (render->vz1.y)-(render->vz2.y), (-render->near_side)-(render->-far_side), (render->near_z)-(render->far_z));
	new_vz.y = vxs(vxs(render->vz1.x,render->vz1.y, render->vz2.x,render->vz2.y), (render->vz1.y)-(render->vz2.y),
			vxs(-render->near_side,render->near_z, render->-far_side,render->far_z), (render->near_z)-(render->far_z))
		/ vxs((render->vz1.x)-(render->vz2.x), (render->vz1.y)-(render->vz2.y), (-render->near_side)-(render->-far_side), (render->near_z)-(render->far_z));
}
