/*
 * Copyright 1998-1999 The OpenLDAP Foundation, All Rights Reserved.
 * COPYING RESTRICTIONS APPLY, see COPYRIGHT file
 */
/*  Portions
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  getentry.c
 */

#include "portable.h"

#include <stdio.h>
#include <stdlib.h>

#include <ac/ctype.h>
#include <ac/socket.h>
#include <ac/string.h>
#include <ac/time.h>

#include "lber.h"
#include "ldap.h"

/* ARGSUSED */
LDAPMessage *
ldap_first_entry( LDAP *ld, LDAPMessage *chain )
{
	return( chain == NULLMSG || chain->lm_msgtype == LDAP_RES_SEARCH_RESULT
	    ? NULLMSG : chain );
}

/* ARGSUSED */
LDAPMessage *ldap_next_entry( LDAP *ld, LDAPMessage *entry )
{
	if ( entry == NULLMSG || entry->lm_chain == NULLMSG
	    || entry->lm_chain->lm_msgtype == LDAP_RES_SEARCH_RESULT )
		return( NULLMSG );

	return( entry->lm_chain );
}

/* ARGSUSED */
int
ldap_count_entries( LDAP *ld, LDAPMessage *chain )
{
	int	i;

	for ( i = 0; chain != NULL && chain->lm_msgtype
	    != LDAP_RES_SEARCH_RESULT; chain = chain->lm_chain )
		i++;

	return( i );
}
